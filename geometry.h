#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "vector.h"
#include "settings.h"

float SegmentLength (vector3f p1, vector3f p2);

typedef struct {
	vector3f color;
	bool light;
	float diff;
	float spec;
	float refl;
	float refr;
} Material;

typedef struct {
	char *name;
	enum {PLANE = 0, SPHERE = 1, POLY = 2} type;
	Material material;
	vector3f normal; //Plane Normal
	vector3f center; //Sphere or Plane Center
	float radius; //Sphere Radius
	int numv; // Number of vertices. 
	vector3f vert[10]; // Array of vertices.
} Primitive;

typedef struct {
	vector3f dir, origin;
} Ray;

vector3f GetPoint(Ray r, float d);

float PlaneIntersect(Ray r, Primitive p) {
	return Dot(sub3f(p.center, r.origin), p.normal) / Dot(r.dir, p.normal);
}

float SphereIntersect(Ray r, Primitive p) {
	bool near = true;
	float a = Dot(r.dir, r.dir);
	float b = Dot(mul3f(r.dir, 2.0f), sub3f(r.origin, p.center));
	float c = Dot(sub3f(r.origin, p.center), sub3f(r.origin, p.center)) - p.radius * p.radius;
	float disc = b * b - 4.0f * a * c;
	float pls, mns;

	if (disc > 0.0f) {
		pls = (-b + sqrtf(disc)) / (2.0f * a);
		if (disc == 0.0f) return pls;
		mns = (-b - sqrtf(disc)) / (2.0f * a);
		if (near) return (pls < mns) ? pls : mns;
		return (pls < mns) ? mns : pls;
	}
	return -1.0f;
}

vector3f PolyNormal(Primitive p) {
	if (p.numv > 3) {
		fprintf(stderr, "Malformed polygon: primitive %s\n", p.name);
		vector3f t = VZERO;
		return t;
	}
	return Normalize(cross3f(sub3f(p.vert[2], p.vert[1]), sub3f(p.vert[0], p.vert[2])));
}

float PolyIntersect(Ray r, Primitive p) {

	return -1.0f;
}

vector3f SphereNormal(vector3f point, Primitive p) {
	return Normalize(sub3f(point, p.center));
}

float Intersect (Ray r, Primitive p) {
	switch (p.type) {
		case 0:
			return PlaneIntersect(r,p);
			break;
		case 1:
			return SphereIntersect(r,p);
			break;
		case 2:
			return PolyIntersect(r,p);
			break;
	}
}

vector3f GetNormal(vector3f point, Primitive p) {
	switch (p.type) {
		case 0:
			return p.normal;
			break;
		case 1:
			return SphereNormal(point, p);
			break;
		case 2:
			return PolyNormal(p);
			break;
	}
}

vector3f Direction (vector3f p1, vector3f p2) {
	return Normalize(sub3f(p1, p2));
}

float SegmentLength (vector3f p1, vector3f p2) {
	return abs(Length(sub3f(p1, p2)));
}

vector3f GetPoint(Ray r, float d) {
	return add3f(r.origin, mul3f(r.dir, d));
}

#endif