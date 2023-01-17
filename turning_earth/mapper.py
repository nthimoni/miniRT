from math import *
nb_map = 200
nb_max_suffix = 1 + (nb_map // 26)
map_name = "earth_"
suff = ord('a');
cam_pos = [0.0, 0.0, 0.0]
camera_distance = 60.0


def def_pos(i):
    teta = (2.0 * pi) * (i / nb_map);
    cam_pos[0] = sin(teta) * camera_distance;
    cam_pos[1] = 0;
    cam_pos[2] = cos(teta) * camera_distance;
    pos = format(cam_pos[0], ".6f") + ",0," + format(cam_pos[2], ".6f")
    return pos


def def_dir():
    length = sqrt(cam_pos[0] * cam_pos[0] + cam_pos[1] * cam_pos[1] + cam_pos[2] * cam_pos[2])
    dir = format(-cam_pos[0] / length, ".6f") + ",0," + format(-cam_pos[2] / length, ".6f")
    return dir




param = open(map_name + "param", "w")
for i in range(0, nb_map + 1):
    suffix = chr(suff + (i // nb_max_suffix))
    name = map_name + str(suffix) * (nb_max_suffix - i % nb_max_suffix) + ".rt"
    param.write(name + " ")
    f = open(map_name + str(suffix) * (nb_max_suffix - i % nb_max_suffix) + ".rt", "w")
    f.write("A 0.3 255,255,255\n")
    pos = def_pos(i)
    direction = def_dir()
    f.write("C " + pos + " " + direction + " " + "70\n")
    f.write("sp 0,0,0     60   earth.xpm\n")
    #f.write("sp 0,0,0     60   earth.xpm/bump.xpm\n")
    f.write("L 0,10,-60 0.8 255,255,255\n")
    f.write("L 0,10,60 0.8 255,255,255\n")
    f.write("anti-aliasing 1\n")
    f.close()
param.close()

