# Ray-Tracer
42 School project. Done with fellow student https://github.com/n0-tail.

# rt

This is a 42 school project. Done with C using Minilibx https://harm-smits.github.io/42docs/libs/minilibx

Right now this project is only supported by Mac os. There is a user tutorial at the end.

The objective was to get familiar with the concept of ray tracing and creating scenes using it. Our ray tracing program uses four different main objects to create its scenes. (Plane, sphere, cylinder and cone). Ring is an extra object you can make from a plane, example in the pic below. 

The program reads the "scene" from a file and creates the 3D images with "realistic" shadows and reflections. It supports textures in P6 ppm format and models/objects in .obj format.


# Little bit of everything:

![scene eval09 image:](https://github.com/Makenfile86/ray-tracer/blob/main/circus.jpg?raw=true)

# Classic RT three spheres:

![scene eval09 image3:](https://github.com/Makenfile86/ray-tracer/blob/main/balls.jpg?raw=true)

# something more outlandish: 

![scene eval09 image3:](https://github.com/Makenfile86/ray-tracer/blob/main/space.jpg?raw=true)

# Pool shots:

![scene eval09 image3:](https://github.com/Makenfile86/ray-tracer/blob/main/billiard.jpg?raw=true)

# Room:

![scene eval09 image3:](https://github.com/Makenfile86/ray-tracer/blob/main/room.jpg?raw=true)

# ** Installation

Clone or download this repository and run "make" in command line while in the root of the repository. This will build executable called rt.

Next you need to create a scene file or use one of the examples from the "scenes" folder.

run ./rt scenes/"scene name" to open a scene.

# Example of a scene file:

![scene eval09 file:](https://github.com/Makenfile86/ray-tracer/blob/main/scene_file.jpg?raw=true)

You need a SCENE, CAMERA, atleast one SPOT (light) and a object.

So first line is  "* SCENE...", Where you first declare where your second lines input goes. To declare data you only need the "* NAME". The variables after that are simply to help you fill the values for them in the same order in the second line. 

Each object has its variables you can manage to create your own scenes, most of the variables overlap but some are unique to a object.

# Scene variables:

| Scene variables.   | Explanation                                                |
|--------------------|------------------------------------------------------------------------------------------------------------------------|
| background.        | Not in operation Right now. Leave it at 0 or 999999, doesnt matter.                                                    |                     | lambert.           | How much lambert you want in your scene, 3-4 is recommended.                                                           |
| light.             | How much overall light power your SPOTS have. 5-7 recommended.                                                         |
| shadows.           | 0 for no shadows, otherwise shadows.                                                                                   |         
| reflection iter.   | Reflection iteration, in theory you dont want reflections reflections. 0-1 is no reflections. 2 is realistic.          |   
| color intensity.   | How intense you want your colors to be, 2-5 is recommended.                                                            |
| reflections.       | How intense you want your reflections to be, 1-5 is realistic.                                                         |


# The object variables:

//the usual variables

| Variable        | Explanation                                                |
|-----------------|---------------------------------------------------------------------------------------------------------------------------|
| Coord-XYZ       | Objects point on 3D space (X, Y, Z), (0, 0, 0) is middle of the screen                                                    |
| Radius / angle  | Objects radius determines the size for sphere,plane and cylinder.	Angle for cone.                                         |
| Color-RGB       | Objects color in RGB format (red, green, blue) , (255, 255, 255) is whitest, (0, 0, 0) is blackest.                       |
| Rotation        | You can rotate the object in 3D space using (X, Y, Z), (0, 0, 0) is no rotation                                           |
| Material        | The material of your object. With "3" the object is see through, with "4" its a mirror. Adjust with Scale variable        |
| TXT-type.       | You can add your own texture to a object or use existing from the resource folder. The format has to be in P6 .ppm format |
|                 | There are also several texture patterns that you can use, like "checker" , "vstripe" , "hstripe" , "gradient" and "split".|
| TXT-size/scale  | You can modify your textures size and you can modify your see through or mirror objects with this variable.               |
|                 | -See through (material 3) with value 1 is thin glass like, the bigger the variable the thicker the glass becomes.         |
|                 | -Mirror (material 4) the bigger the variable to more the mirror has its own objects color blended into it.                |
|                 | -Textures the bigger the value the bigger the texture pattern is.                                                         |
| TXT-color       | When using texture patterns they often use two different colors, this is where you can add the other color in RGB format. |

//Object specific variables

| Plane variables    | Explanation                                                
|--------------------|------------------------------------------------------------------------------------------------------------------------|
| Normal-XYZ         | To move the Plane in 3D space you need to adjust the Planes normal. if Coord-XYZ is (-75, 19, 35) and you want         |
|                    | the plane in that position while being flat to the ground you need to adjust the Normal-XYZ to (-75, 0, 35).           |
| Ring               | You can make a ring out of a plane by adjusting the Ring variable, bigger the variable the larger the hole.            |

| Cylinder variables | Explanation                                                
|--------------------|------------------------------------------------------------------------------------------------------------------------|
| End-XYZ            | The Cylinder has a starting and ending point (X, Y, Z) in 3D space. With endpoint you can determine in which direction |                     | the cylinder points to. If start is (-15, 0, 80)  and end is (-10, 5, 80) The cylinder is  tilted towards right.                            |
|                    | in that position while being flat to the ground you need to adjust the Normal-XYZ to (-75, 0, 35).                     |
| Height             | Height determines the length of the cylinder.                                                                          |

| Camera variables   | Explanation                                                
|--------------------|------------------------------------------------------------------------------------------------------------------------|
| Target-XYZ         | Target is the point where the camera faces in 3D space. (0, 0, 0) is middle                                            |    

| SPOT variables     | Explanation                                                
|--------------------|------------------------------------------------------------------------------------------------------------------------|
| power              | Each spot has its own power variable, determines how much light the spot produces                                      |  



