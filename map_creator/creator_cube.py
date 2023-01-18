from math import *
from random import randint
map_name = "cylinder2.rt"
sph_pos = [0.0, 0.0, 0.0]
lim_min = -50
lim_max = 50
step = 20


def pos(i, j, k):
    pos = [i, j, k]
    pos = [str(x) for x in pos]
    return ','.join(pos)


def dir(i, j):
    pos = [i, j, k]
    pos = [str(x) for x in pos]
    return ','.join(pos)


def rad():
    radius = 5
    return radius


def col():
    value = [randint(0, 255), randint(0, 255), randint(0, 255)]
    value = [str(x) for x in value]
    return ','.join(value)


f = open(map_name, "w+")
f.write("A 0.2 255,255,255\n")
f.write("C 0,0,-150 0,0,1 70\n")
for i in range(lim_min, lim_max, step):
    for j in range(lim_min, lim_max, step):
        for k in range(lim_min, lim_max, step):
            f.write(f"cy {pos(i, j, k)} 1,0,0 2 20 255,255,255\n")
            f.write(f"cy {pos(i, j, k)} 0,1,0 2 20 255,255,255\n")
            f.write(f"cy {pos(i, j, k)} 0,0,1 2 20 255,255,255\n")
for i in range(lim_min, lim_max, step):
    for j in range(lim_min, lim_max, step):
        f.write(f"cy {pos(i, j, lim_max)} 0,1,0 2 20 255,255,255\n")
        f.write(f"cy {pos(i, j, lim_max)} 1,0,0 2 20 255,255,255\n")
for i in range(lim_min, lim_max, step):
    for k in range(lim_min, lim_max, step):
        f.write(f"cy {pos(i, lim_max, k)} 1,0,0 2 20 255,255,255\n")
        f.write(f"cy {pos(i, lim_max, k)} 0,0,1 2 20 255,255,255\n")
for j in range(lim_min, lim_max, step):
    for k in range(lim_min, lim_max, step):
        f.write(f"cy {pos(lim_max, j, k)} 0,1,0 2 20 255,255,255\n")
        f.write(f"cy {pos(lim_max, j, k)} 0,0,1 2 20 255,255,255\n")

f.write("L 0,60,-100 0.5 255,255,255\n")
f.write(f"L 0,0,0 0.5 {col()}\n")
#f.write(f"L 25,25,25 0.8 {col()}\n")
#f.write(f"L -25,25,25 0.8 {col()}\n")
#f.write(f"L -25,-25,25 0.8 {col()}\n")
#f.write(f"L 25,-25,25 0.8 {col()}\n")
#f.write(f"L 25,25,-25 0.8 {col()}\n")
#f.write(f"L -25,25,-25 0.8 {col()}\n")
#f.write(f"L -25,-25,-25 0.8 {col()}\n")
#f.write(f"L 25,-25,-25 0.8 {col()}\n")
f.write(f"pl -100,0,0 1,0,0 150,150,150\n")
f.write(f"pl 100,0,0 1,0,0 150,150,150\n")
f.write(f"pl 0,100,0 0,1,0 150,150,150\n")
f.write(f"pl 0,-100,0 0,1,0 150,150,150\n")
f.write(f"pl 0,0,100 0,0,1 150,150,150\n")
f.write("anti-aliasing 10\n")
f.close()
