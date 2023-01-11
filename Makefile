SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
FTPATH = libft/
MLXPATH = minilibx-linux/
FTINC = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a
MLX = $(MLXPATH)libmlx.a
######################################################################
SRCS =	maths/ft_atof.c \
	  	maths/ft_atof_utils.c\
	  	maths/matrix.c\
	  	maths/matrix2.c\
	  	maths/matrix3.c\
	  	maths/matrix4.c\
	  	maths/matrix_test.c\
	  	maths/transformations.c\
	  	maths/transformations2.c\
	  	maths/vector.c\
	  	maths/vector2.c\
	  	maths/vector3.c\
	  	scene/camera.c\
	  	scene/obj.c\
	  	primitives/cone.c\
	  	primitives/cylinder.c\
	  	primitives/plane.c\
	  	primitives/sphere.c\
	  	rendering/hook.c\
	   	rendering/image.c\
	  	rendering/init.c\
	  	rendering/intersect.c\
	  	rendering/ray.c\
	  	rendering/rendering.c\
	  	utils/debug.c\
	  	utils/print.c\
	  	utils/test.c\
		main.c exit_rt.c trash.c colors.c \
		parsing.c parsing_utils.c data_parser.c obj_filler.c lighting.c\
		isShadowed.c text_mapping.c bump_map.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
DEPENDS = $(OBJS:.o=.d)
######################################################################
CC = gcc -O3#-g -fsanitize=address -lasan
CFLAGS = #-Wall -Wextra -Werror -MMD -MP 

LINK = -lmlx -lft -lm -lXext -lX11
INCPATH = -I$(INCDIR) -I$(FTINC) -I$(MLXPATH)
LIBPATH = -L$(FTPATH) -L$(MLXPATH)
NAME = miniRT
MAP = input.rt
VAL = valgrind --leak-check=full ./$(NAME) $(MAP)
RUN = ./$(NAME) $(MAP)
######################################################################
all: $(NAME)
	$(RUN)

$(NAME): $(OBJDIR) $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)

-include $(DEPENDS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(LIBFT):
	make -C $(FTPATH)

$(MLX):
	make -C $(MLXPATH)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/maths
	@mkdir -p $(OBJDIR)/scene
	@mkdir -p $(OBJDIR)/primitives
	@mkdir -p $(OBJDIR)/rendering
	@mkdir -p $(OBJDIR)/utils

run:
	$(RUN)

val:
	$(VAL)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	#make fclean -C $(FTPATH)
	#make clean -C $(MLXPATH)
	rm -f $(NAME)

re: fclean $(NAME) run

.PHONY: all libft clean fclean re
