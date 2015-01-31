#ifndef _SCENE_H
#define _SCENE_H

//-----------------
//Scene Description
//-----------------

/*static const int numpr = 3;

Primitive prim[] = {
	{
		.name = "poly", 
		.type = POLY,
		.material = {
			.color = {1.0f, 0.0f, 0.0f}, 
			.light = false, 
			.diff = 0.5f,
			.spec = 0.0f,
			.refl = 0.5f,
			.refr = 0.0f
		},
		.numv = 3,
		.vert = {{200.0f, 200.0f, 300.0f}, {250.0f, 250.0f, 300.0f}, {250.0f, 150.0f, 325.0f}}
	},
	{
		.name = "light_2",
		.type = SPHERE,
		.material = {
			.color = {1.0f, 1.0f, 1.0f},
			.light = true,
			.diff = 0.0f,
			.spec = 0.0f,
			.refl = 0.0f,
			.refr = 0.0f
		},
		.center = {1240.0f, 400.0f, -500.0f},
		.radius = 10.0f
	},
	{
		.name = "plane_1",
		.type = PLANE,
		.material = {
			.color = {1.0f, 1.0f, 1.0f},
			.light = false,
			.diff = 1.0f,
			.spec = 0.5f,
			.refl = 0.0f,
			.refr = 0.0f
		},
		.normal = {-0.5f, 0.0f, -1.0f},
		.center = {320.0f, 240.0f, 625.0f}
	}
};*/

static const int numpr=9;

Primitive prim[] = {
	{
		.name = "sphere_1", 
		.type = SPHERE,
		.material = {
			.color = {1.0f, 0.0f, 0.0f}, 
			.light = false, 
			.diff = 0.5f,
			.spec = 0.0f,
			.refl = 0.5f,
			.refr = 0.0f
		},
		.center = {233.0f, 290.0f, 325.0f},
		.radius = 75.0f
	},
	{
		.name = "sphere_2",
		.type = SPHERE,
		.material = {
			.color = {0.0f, 1.0f, 0.0f},
			.light = false,
			.diff = 0.5f,
			.spec = 0.0f,
			.refl = 0.5f,
			.refr = 0.0f
		},
		.center = {407.0f, 290.0f, 325.0f},
		.radius = 75.0f
	},
	{
		.name = "sphere_3",
		.type = SPHERE,
		.material = {
			.color = {0.0f, 0.0f, 1.0f},
			.light = false,
			.diff = 0.5f,
			.spec = 0.0f,
			.refl = 0.5f,
			.refr = 0.0f
		},
		.center = {320.0f, 140.0f, 325.0f},
		.radius = 75.0f
	},
	{
		.name = "clear_sphere",
		.type = SPHERE,
		.material = {
			.color = {1.0f, 1.0f, 1.0f},
			.light = false,
			.diff = 0.0f,
			.spec = 0.01f,
			.refl = 0.5f,
			.refr = 1.62f
		},
		.center = {320.0f, 240.0f, -300.0f},
		.radius = 50.0f
	},
//	{
//		.name = "light_1",
//		.type = SPHERE,
//		.material = {
//			.color = {0.6f, 0.6f, 0.6f},
//			.light = false,
//			.diff = 0.0f,
//			.refl = 0.0f,
//			.refr = 0.0f
//		},
//		.center = {0.0f, 0.0f, -1000.0f},
//		.radius = 0.1f
//	},
	{
		.name = "light_2",
		.type = SPHERE,
		.material = {
			.color = {1.0f, 1.0f, 1.0f},
			.light = true,
			.diff = 0.0f,
			.spec = 0.0f,
			.refl = 0.0f,
			.refr = 0.0f
		},
		.center = {1240.0f, 400.0f, -500.0f},
		.radius = 10.0f
	},
	{
		.name = "plane_1",
		.type = PLANE,
		.material = {
			.color = {1.0f, 1.0f, 1.0f},
			.light = false,
			.diff = 1.0f,
			.spec = 0.5f,
			.refl = 0.0f,
			.refr = 0.0f
		},
		.normal = {-0.5f, 0.0f, -1.0f},
		.center = {320.0f, 240.0f, 625.0f}
	},
	{
		.name = "sphere 4",
		.type = SPHERE,
		.material = {
			.color = {0.0f, 1.0f, 1.0f},
			.light = false,
			.diff = 0.5f,
			.spec = 0.2f,
			.refl = 0.5f,
			.refr = 0.0f
		},
		.center = {400.0f, 190.0f, -50.0f},
		.radius = 75.0f
	},
	{
		.name = "sphere 5",
		.type = SPHERE,
		.material = {
			.color = {1.0f, 0.0f, 1.0f},
			.light = false,
			.diff = 0.5f,
			.spec = 0.5f,
			.refl = 0.5f,
			.refr = 0.0f
		},
		.center = {240.0f, 190.0f, -50.0f},
		.radius = 75.0f
	},
	{
		.name = "sphere 6",
		.type = SPHERE,
		.material = {
			.color = {1.0f, 1.0f, 0.0f},
			.light = false,
			.diff = 0.5f,
			.spec = 0.0f,
			.refl = 0.5f,
			.refr = 0.0f
		},
		.center = {320.0f, 330.0f, -50.0f},
		.radius = 75.0f
	}	
};

#endif