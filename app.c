#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "vector.h"
#include "raytrace.h"
#include "geometry.h"
#include "scene.h"
#include "settings.h"
#include "SDL/SDL.h"
#include "SDL/SDL_draw.h"

SDL_Surface *screen;
SDL_Event event;

bool neg_bool(bool x) {
	if (x) return false;
	else return true;
}

//* Point in Polygon *//
bool pip(int nv, vector3f *verts, int x, int y) {
	int i,j = nv-1, count = 0;
	for (i=0; i<nv; i++) {
		if ((verts[i].y > y) != (verts[j].y > y)) {
			if (x < 
			(verts[j].x - verts[i].x) *	
			(y - verts[i].y) / 
			(verts[j].y - verts[i].y) +
			verts[i].x) {
				count++;
			}
		}
		j = i;
	}
	if ((count != 0) && (count % 2 != 0)) return true;
	return false;
}

/*void FillRect(int x, int y, int w, int h, int color) {
	SDL_Rect rect = {x,y,w,h};
	SDL_FillRect(screen, &rect, color);
}*/

void setpixel(SDL_Surface *screen, int x, int y, Uint32 color)
{
    Uint32 *pixmem32;
	int ytimesw = y*screen->pitch/BPP;  
    pixmem32 = (Uint32*)screen->pixels + ytimesw + x;
    *pixmem32 = color;
}

//---------
//Rendering
//---------

void render() {   
	
	vector3f rgb, rgb2;
	Uint32 color;
	int x,y;
	float xx, yy;
	Primitive pp, lp = {.name = ""};
	
    // Lock surface if needed
    if (SDL_MUSTLOCK(screen)) 
		if (SDL_LockSurface(screen) < 0) 
			return;
	
	// Rendering happens here
#ifndef DEBUG
	for (x=0; x<SZ_X; x++) for (y=0; y<SZ_Y; y++) {
		pp = raytrace(pixtoray((float)x,(float)y),0, &rgb);
		rgb = mul3f(rgb, 255.0f);
		color = SDL_MapRGB(screen->format, rgb.x, rgb.y, rgb.z);
		setpixel(screen, x, y, color);
	}
	int i,j;	
	for (i=0; i<numpr; i++) {
		if (prim[i].type == POLY) {
			for (j=0; j<prim[i].numv; j++) {
				Draw_Circle(screen, prim[i].vert[j].x, prim[i].vert[j].y, 5, 0xff0000);
			}
		}
	}
#endif
#ifdef DEBUG
	vector3f p1 = {10.0f, 10.f, 0.0f}, p2 = {50.0f, 50.0f, 0.0f}, p3 = {100.0f, 20.0f, 0.0f};
	Draw_Line(screen, p1.x, p1.y, p2.x, p2.y, 0xffffff);
	Draw_Line(screen, p2.x, p2.y, p3.x, p3.y, 0xffffff);
	Draw_Line(screen, p3.x, p3.y, p1.x, p1.y, 0xffffff);
	int nv = 3;
	vector3f points[3] = {p1, p2, p3};
	for (x=0; x<SZ_X; x++) for (y=0; y<SZ_Y; y++) {
		if (pip(nv, &points[0], x, y)) setpixel(screen, x, y, 0xff0000);
	}

#endif

	// Unlock if needed
	SDL_MUSTLOCK(screen) ? : SDL_UnlockSurface(screen);
	
	// Tell SDL to update the whole screen
	//SDL_UpdateRect(screen,0,0,0,0);
	SDL_Flip(screen);
}

//------------
//Main Program
//------------

int main(int argc, char *argv[]) {

	// Initialize SDL's subsystems - in this case, only video.
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
    }

    // Register SDL_Quit to be called at exit.
    atexit(SDL_Quit);
	
	// Set Window Title
	SDL_WM_SetCaption("Raytracer Test","Raytracer Test");
    
    // Attempt to create a window with 32bit pixels.
    screen = SDL_SetVideoMode(SZ_X, SZ_Y, DEPTH, SDL_SWSURFACE);
  
    if (screen == NULL) {
		fprintf(stderr, "Unable to set video %dx%d-%d: %s\n", SZ_X, SZ_Y, DEPTH, SDL_GetError());
		exit(1);
	}
	
	render();
	
	while (1) {
		
		//Poll for events.
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
		
				case SDL_KEYDOWN:
				break;
			
				case SDL_KEYUP:
					//If escape is pressed, return
					if (event.key.keysym.sym == SDLK_ESCAPE) {return 0;}
				break;
			
				case SDL_QUIT:
					return(0);		
			}
		}
	}
	return(0);
}	