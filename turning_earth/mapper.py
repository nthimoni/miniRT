from math import *
nb_map = 20;
map_name = "earth_"
suff = ord('a');
cam_pos = [0.0, 0.0, 0.0]
camera_distance = 60


def def_pos(i):
    teta = 2 * pi / i;
    cam_pos[0] = sin(teta) * camera_distance;
    cam_pos[1] = 0;
    cam_pos[2] = cos(teta) * camera_distance;
    pos = format(cam_pos[1], ".2f") + ",0," + format(cam_pos[2], ".2f")
    return pos


def def_dir():
    length = sqrt(cam_pos[0] * cam_pos[0] + cam_pos[1] * cam_pos[1] + cam_pos[2] * cam_pos[2])
    dir = format(-cam_pos[0] / length, ".2f") + ",0," + format(-cam_pos[2] / length, ".2f")
    return dir




for i in range(1, nb_map):
    suffix = chr(suff + i)
    f = open(map_name + str(suffix) + ".rt", "w")
    f.write("A 0.3 255,255,255\n")
    pos = def_pos(i)
    direction = def_dir()
    f.write("C " + pos + " " + direction + " " + "70\n")
    f.write("sp 0,0,0     60   earth.xpm/bump.xpm\n")
    f.write("L 0,0,-60 0.8 255,255,255\n")


