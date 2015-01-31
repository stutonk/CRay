#ifndef _RAYTRACE_H
#define _RAYTRACE_H

#include <stdio.h>
#include <math.h>
#include "vector.h"
#include "geometry.h"
#include "scene.h"
#include "settings.h"

vector3f shade(Ray r, int index, vector3f point);
Primitive raytrace(Ray r, int d, vector3f *Final);

//------------
// Ray tracing
//------------

Ray Reflect(Ray r, vector3f N, vector3f point, Primitive p) {
	if (!p.type) N = Normalize(N);
	Ray ref = {sub3f(r.dir, mul3f(mul3f(N, 2.0f), Dot(r.dir, N))), point};
	return ref;
}

vector3f Refract(Ray r, vector3f N, vector3f point, Primitive p) {
	float n = refrair / p.material.refr;
	float cosI = Dot(N, r.dir) * -1.0f;
	float cosT2 = 1.0f - n * n * (1.0 - cosI * cosI);
	if (cosT2 > 0.0f) {
		vector3f T = add3f(mul3f(r.dir, n), mul3f(N, (n * cosI - sqrtf(cosT2))));
		Ray x = {T, add3f(point, T)};
		vector3f o;
		Primitive pp = raytrace(x, 0, &o);
		return o;
	}
	vector3f q = VZERO;
	return q;
}

vector3f shade(Ray r, int index, vector3f point) {
	int i, j;
	float dot, diff, dist, d2, spec, shadow = 1.0f;
	vector3f Color = VZERO;
	
	//diffuse shading and shadows
	for (i=0; i<numpr; i++) {
		if (i == index) continue;
		if (prim[i].material.light) {		
			Ray ab = {.dir = Direction(prim[i].center, point), .origin = point}; //Light ray
			dist = SegmentLength(prim[i].center, point);
			for (j=0; j<numpr; j++) {
				if (j == i) continue;
				d2 = SegmentLength(prim[i].center, GetPoint(ab, Intersect(ab, prim[j])));
				if (fabs(d2) < fabs(dist) && d2 != -1.0f) {
					shadow = 0.5f;
					break;
				}
			}
			dot = Dot(GetNormal(point, prim[index]), Direction(prim[i].center, point));
			if (dot > 0) {
				diff = dot * prim[index].material.diff * shadow;
				Color = add3f(Color, mul3f2(mul3f(prim[index].material.color, diff), prim[i].material.color));
			}
			// Phong specularity
			if (prim[index].material.spec > 0.0f) {
				vector3f N = GetNormal(point, prim[index]);
				vector3f V = r.dir;
				vector3f R = sub3f(ab.dir, mul3f(N, 2.0f * Dot(ab.dir, N)));
				float dot2 = Dot(V, R);
				if (dot2 > 0.0f) {
					float cspec = powf(dot2, 15.0f) * prim[index].material.spec * shadow;
					Color = add3f(Color, mul3f(prim[i].material.color, cspec));
				}
			}
		}
	}
	
	return Color;
}

Primitive raytrace(Ray r, int d, vector3f *Final) {
	vector3f ZV = VZERO, poi;
	float dist = 1000000.0f, cdist;
	int index = -1, i;
	*Final = ZV;
	Primitive nul = {.name = ""};
	
	for (i=0; i<numpr; i++) {
		cdist = Intersect(r, prim[i]);
		if (cdist >= 0.0f) {
			if (cdist < dist && cdist > 0) {dist = cdist; index = i;}			
		}
	}	
	if (index < 0) return nul;
	if (prim[index].material.light) {*Final = prim[index].material.color; return prim[index];}//return prim[index].material.color;
	
	poi = GetPoint(r, dist);

	*Final = add3f(*Final, shade(r, index, poi));
	
	if (prim[index].material.refl > 0.0f && ++d < refldepth) {
		vector3f tc = VZERO;
		Primitive pp = raytrace(Reflect(r, GetNormal(poi, prim[index]), poi, prim[index]), d, &tc);
		*Final = add3f(*Final, mul3f(tc, prim[index].material.refl));
	}
	
	if (prim[index].material.refr > 0.0f) {
			*Final = add3f(*Final, mul3f2(prim[index].material.color, Refract(r, GetNormal(poi, prim[index]), poi, prim[index])));
	}
	
	if (Final->x > 1.0f) Final->x = 1.0f;
	if (Final->y > 1.0f) Final->y = 1.0f;
	if (Final->z > 1.0f) Final->z = 1.0f;
	
	return prim[index];
	//return Final;
}

Ray pixtoray(float x, float y) {
#ifdef CONIC
	vector3f org = {(float)(SZ_X / 2), (float)(SZ_Y / 2), -1000.0f};
	vector3f p = {(float)x, (float)y, 0.0f};
	Ray o = {Direction(p, org), org};
	return o;
#endif
#ifdef ORTHOGRAPHIC
	Ray o = {{ 0.0f, 0.0f, 1.0f},{(float)x, (float)y, -1.0f}};
#endif
	return o;
}

#endif