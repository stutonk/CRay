#ifndef _VECTOR_H
#define _VECTOR_H

#include <math.h>

//vector3f

typedef struct {
	float x, y, z;
} vector3f;

vector3f add3f(vector3f v1, vector3f v2) {
	vector3f o; 
	o.x = v1.x + v2.x; 
	o.y = v1.y + v2.y; 
	o.z = v1.z + v2.z; 
	return o;
}

vector3f sub3f(vector3f v1, vector3f v2) {
	vector3f o; 
	o.x = v1.x - v2.x; 
	o.y = v1.y - v2.y; 
	o.z = v1.z - v2.z; 
	return o;
}

vector3f mul3f(vector3f v, float f) {
	vector3f o; 
	o.x = v.x * f; 
	o.y = v.y * f; 
	o.z = v.z * f; 
	return o;
}

vector3f div3f(vector3f v, float f) {
	vector3f o; 
	o.x = v.x / f; 
	o.y = v.y / f; 
	o.z = v.z / f; 
	return o;
}

vector3f mul3f2(vector3f v1, vector3f v2) {
	vector3f o;
	o.x = v1.x * v2.x;
	o.y = v1.y * v2.y; 
	o.z = v1.z * v2.z; 
	return o;
}

vector3f cross3f(vector3f v1, vector3f v2) {
	vector3f o; 
	o.x = v1.y * v2.z - v1.z * v2.y;
	o.y = v1.z * v2.x - v1.x * v2.z; 
	o.z = v1.x * v2.y - v1.y * v2.x; 
	return o;
}

float Length(vector3f v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float SqLength(vector3f v) {
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

float Dot(vector3f v, vector3f w) {
	return v.x * w.x + v.y * w.y + v.z * w.z;
}

vector3f Normalize(vector3f v) {
	float l = Length(v); 
	v.x /= l; v.y /= l; v.z /= l;
	return v;
}

vector3f Negate(vector3f v) {
	vector3f o;
	o.x = -v.x;
	o.y = -v.y;
	o.z = -v.z;
	return o;
}

//vector2i

int gcd(int a,int b) {
	int c;
	while(1) {
	c = a%b;
	if(c==0)
		return b;
		a = b;
		b = c;
	}
}

typedef struct {
	int x, y;
} vector2i;

vector2i aspect(int x, int y) {
	if (!(x % 1 == 0) || !(y % 1 == 0)) {
		x *= 10; y *= 10;
	}
	int div = gcd(x, y);
	vector2i o = {.x = x/div, .y = y/div};
	return o;
}

#endif