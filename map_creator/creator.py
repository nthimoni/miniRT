from math import *
from random import randint
map_name = "sphere.rt"
sph_pos = [0.0, 0.0, 0.0]


def pos(i, j):
    pos = [i, randint(-50, 50), j]
    pos = [str(x) for x in pos]
    return ','.join(pos)


def rad(i, j):
    radius = randint(4, 20)
    return radius


def col(i, j):
    value = [randint(0, 255), randint(0, 255), randint(0, 255)]
    value = [str(x) for x in value]
    return ','.join(value)


f = open(map_name, "w+")
f.write("A 0.3 255,255,255\n")
f.write("C 0,0,-150 0,0,1 70\n")
for i in range(-200, 200, 20):
    for j in range(-200, 200, 20):
        f.write(f"sp {pos(i, j)} {rad(i, j)} {col(i, j)}\n")
f.write("L 0,60,-100 0.8 255,255,255\n")
f.write("anti-aliasing 10\n")
f.close()
