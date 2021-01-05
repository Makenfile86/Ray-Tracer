# Ray-Tracer
42 School project, not finished.

# rt
//

This is a 42 school project. Done with C using Minilibx https://harm-smits.github.io/42docs/libs/minilibx
Right now its only supported by Mac os. There is a user tutorial at the end.

The objective was to get familiar with the concept of ray tracing and creating scenes using it. Our ray tracing program uses four different objects to create its scenes.
(Plane, sphere, cylinder and cone). The program reads the "scene" from a file and creates the 3D images with "realistic" shadows and reflections. It supports textures in P6 ppm format and has a few different texture mapping patterns. 


Quakeish scene:

![scene eval09 image:](https://github.com/Makenfile86/ray-tracer/blob/main/rt1.jpg?raw=true)

From other camera angle:

![scene eval09 image2:](https://github.com/Makenfile86/ray-tracer/blob/main/rt2.jpg?raw=true)

something more cartoonish: 

![scene eval09 image3:](https://github.com/Makenfile86/ray-tracer/blob/main/ballroom1.jpg?raw=true)

angle from behind:

![scene eval09 image3:](https://github.com/Makenfile86/ray-tracer/blob/main/ballroom2.jpg?raw=true)

** Installation

Clone or download this repository and run "make" in command line while in the root of the repository. This will build executable called rt.

Next you need to create a scene file or use one of the examples from the "scenes" folder.

run ./rt scenes/"scene name" to open a scene.

Example of the scene file:

![scene eval09 file:](https://github.com/Makenfile86/ray-tracer/blob/main/scene_file.jpg?raw=true)

You need a SCENE, CAMERA, atleast one SPOT (light) and a object.

So first line is  "* SCENE...", Where you first declare where your second lines input goes. To declare data you only need the "* NAME". The variables after that are simply to help you fill the values for them in the same order in the second line. 

Each object has its coordinates, size, color and position according to possible rotation values. There is also a camera you can move that faces towards "target". Spot(s) are light sources and you can change their position and light power.

Here is more details about the variables:

background (You can only use this with the SCENE and it draws a background to your scene, its not working completely yet so its recommended to leave at 0).

lambert (how much lambert you want in your scene, 3-4 is recommended).

light (You can change all of the light sources "power").

shadows (0 no shadows, otherwise shadows).

reflection_iteration (1 is no reflections, 2 is realistic reflections, more than 2 your reflections will have reflections and not really recommended).

color_intesity (How intense you want your colors to be ?, 2-5 is recommended).

reflection (How intense you want your reflections to be? 1-5 is recommended).

power (spots lights power).

coord-XYZ (ALl the objects, spots and camera has the XYZ value that determine the location of that item in the 3D space. 0 0 0 is the center).

radius (The radius of the object. Determines the size of the object)

color-RGB (The objects color in RGB, red green blue values between 0-255).

rotation (objects rotational angle, you can rotate certain objects in the 3D space. 0 0 0 is no roation).

material (What kind of material is the object, 1 is very little reflection, 2 is the normal, 4 is like a mirror).

txt_type (You can texture map a texture on the objects surface, 1 is a checker pattern, 3 is a earth texture, 4 is a moon texture, 5 is a marble texture).

txt_size (This determines the size of the texture or the pattern if you are using one, you can choose how big your checker patterns are for example).

txt_color (This determines the "other" color in the checker pattern, default is 0 0 0 black).

normal (Only for planes, planes are flat rounded massive surfaces but you can turn their center to face other directions, 0 0 0 is default).

After using makefi






