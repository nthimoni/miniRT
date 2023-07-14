# miniRT 

---

## 42-Subject

miniRT is a graphic prooject at 42 School. The aim is to realize a more or less simple ray tracer, with the following obligations :

- Draw some forms : sphere, cylinder, cone
- Materialize light : ambient, shadow and phong model
- Create some textures : chess and bitmap

BONUS features (outside of the project) :
- Anti-aliasing
- Map generator
- Turning earth generator

---

## How to use it ?

### Requirements

None

### Examples

`make` and `./miniRT map1 map2 map3 map4 etc.`

Like `./miniRT input/classic.rt`. The rendering of map1 will be replaced by map2 as soon as it is rendered. Rendering time will appear in the terminal.

All maps are stored in `input` directory. 

Some of them have anti-aliasing. Just look for the line with anti-aliasing and add '-' in front of it to avoid it. Ex : `-anti-aliasing 10`

---

## Examples

**Easy stuff - BOULES.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/8fd04a59-d86b-4db0-b586-f843f85d243d)

**Inside Cylinder - in_cylinder.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/a85266d2-b56d-43e9-a130-5682236880a9)

**Playing with colored lights - input.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/69278695-4da1-4a2f-918e-71369a3b57e1)

**Adding chess texture - classic.rt:**
![image](https://github.com/nthimoni/miniRT/assets/87602480/e1d9bf80-850e-423f-97ef-69d8999848c8)

**Spheres - input_long/spheres.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/a3ec14a7-08ef-4068-9caa-8cc008282703)

**Cylinder - input_long/cylinders2.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/4fc5a3ea-fe3a-4c7d-82d8-ed0adb95a268)

---

## Main topics learned in this project

- Library MLX (MiniLibX) : Graphical windows, images and hooks among other things. Deeper knowledge than for fdf.

- Maths : vectors, matrixes, transformation

- Rays : intersections, normal to the intersections

- Light and shading : Reflection, phong models, shadows

- Parsing: Still some parsing to do, but not so difficult

- Optimization : Rendering is long, the more complex the projet (reflexion, refraction, scenes, etc.) the longer it takes to render.

---

## Useful links to realize this project

The Ray Tracer Challenge - Jamis Buck

[3D rendering : https://www.kmjn.org/notes/3d_rendering_intro.html ](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

Download the good MLX : https://github.com/42Paris/minilibx-linux/blob/master/mlx.h 

3D Rendering : https://www.scratchapixel.com/

Rotation matrix : https://gist.github.com/kevinmoran/b45980723e53edeb8a5a43c49f134724
