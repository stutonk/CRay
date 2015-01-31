CRay
====
A ray tracer in C using the SDL and SDL_draw libraries

##Notes
The commentary on this code is pretty light but basically what's going on is for each pixel in the screen, a theoretical ray is traced for a specified distance. The ray hitting objects causes the color to change based on the object's color, transparency, lighting, etc. Settings can be adjusted in settings.h. You can change the scene around by altering scene.h

Currently implemented features include: sphere and plane primitives, reflectivity, transparency with refractivity, Blinn-Phong specularity

For building on non-Linux systems, you can alter the make.sh to suit your own needs (You may need need libm, etc)

##Instructions (Linux)
**Before building:** Make sure you have the development versions of the SDL and SDL_Draw libraries installed and paths configured properly

- git clone https://github.com/stutonk/CRay.git
- cd CRay
- chmod +x make.sh
- /make.sh
- /CRay
