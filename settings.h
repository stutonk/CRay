#ifndef _SETTINGS_H
#define _SETTINGS_H

//Screen dimensions
#define WIDTH 640
#define HEIGHT 480
#define BPP 4
#define DEPTH 32
static const int SZ_X = WIDTH; //Window size x
static const int SZ_Y = HEIGHT; //Window size y

//Debug switch
//#define DEBUG

//Null vector
#define VZERO {0.0f, 0.0f, 0.0f}

//Maximum reflection depth
static const int refldepth = 3;

//Air refractivity
static const float refrair = 1.0003;

//Projection type
#define CONIC
//#define ORTHOGRAPHIC

#endif