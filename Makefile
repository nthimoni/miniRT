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
	  	maths/math_utils.c\
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
	  	mlx_utils/hook.c\
	   	mlx_utils/image.c\
		parser/data_parser.c\
		parser/obj_filler.c\
		parser/parsing.c\
		parser/parsing_utils.c\
	  	primitives/cone.c\
	  	primitives/cylinder.c\
	  	primitives/sphere.c\
	  	primitives/plane.c\
		rendering/bump_map.c\
		rendering/colors.c\
	  	rendering/init.c\
	  	rendering/intersect_utils.c\
		rendering/isShadowed.c\
		rendering/lighting.c\
	  	rendering/ray.c\
		rendering/text_mapping.c\
	  	scene/camera.c\
	  	scene/obj.c\
		utils/exit_rt.c\
	  	utils/print.c\
	  	utils/test.c\
		main.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
DEPENDS = $(OBJS:.o=.d)
######################################################################
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -MMD -MP
LINK = -lmlx -lft -lm -lXext -lX11
INCPATH = -I$(INCDIR) -I$(FTINC) -I$(MLXPATH)
LIBPATH = -L$(FTPATH) -L$(MLXPATH)
NAME = miniRT
MAP = input.rt
VAL = valgrind --leak-check=full ./$(NAME) input.rt
RUN = ./$(NAME) input/$(MAP)
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
	@mkdir -p $(OBJDIR)/mlx_utils
	@mkdir -p $(OBJDIR)/parser
	@mkdir -p $(OBJDIR)/primitives
	@mkdir -p $(OBJDIR)/rendering
	@mkdir -p $(OBJDIR)/scene
	@mkdir -p $(OBJDIR)/utils

run:
	$(RUN)

val:
	$(VAL)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(FTPATH)
	make clean -C $(MLXPATH)
	rm -f $(NAME)

re: fclean $(NAME) run

.PHONY: all libft clean fclean re
