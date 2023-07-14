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

**Playing with colored lights - colored_lights.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/69278695-4da1-4a2f-918e-71369a3b57e1)

**Adding chess texture - classic.rt:**
![image](https://github.com/nthimoni/miniRT/assets/87602480/e1d9bf80-850e-423f-97ef-69d8999848c8)

**Spheres - input_long/spheres.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/a3ec14a7-08ef-4068-9caa-8cc008282703)

**Cylinder - input_long/cylinders2.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/4fc5a3ea-fe3a-4c7d-82d8-ed0adb95a268)

**Cyliner (without ambient light) - input_long/cylinerders.rt :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/45e34c47-3c5d-4069-b3cd-be7f19d841c5)

**ft_earth :**
![image](https://github.com/nthimoni/miniRT/assets/87602480/a834fc65-369b-47da-be79-0dc0e2a95ebf)
![image](https://github.com/nthimoni/miniRT/assets/87602480/36132034-95a8-486e-9d69-7f28ece806b5)
![image](https://github.com/nthimoni/miniRT/assets/87602480/d1fe9351-be06-42b5-8441-b24f1b9ad7b1)
![image](https://github.com/nthimoni/miniRT/assets/87602480/59e7e52b-466a-4235-a508-ced3c862283c)

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