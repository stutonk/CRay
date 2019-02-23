CRay
====
A ray tracer in C using the SDL and SDL_draw libraries

### Notes
This was a project conducted as an experiment and has not been properly documented or maintained. It used the now legacy version 1 of the SDL library. Basically what's going on is for each pixel in the screen, a theoretical ray is traced for a specified distance. The ray hitting objects causes the color to change based on the object's color, transparency, lighting, etc. Settings can be adjusted in settings.h. You can change the scene around by altering scene.h

Currently implemented features include: sphere and plane primitives, reflectivity, transparency with refractivity, Blinn-Phong specularity

### Building
deps: SDL, SDL_Draw, libm

`make`
