SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
FTPATH = libft/
MLXPATH = minilibx-linux/
FTINC = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a
MLX = $(MLXPATH)libmlx.a
######################################################################
SRCS = main.c vector.c image.c hook.c exit_rt.c print.c init.c test.c trash.c colors.c matrix.c transformations.c\
   ft_atof.c ft_atof_utils.c parsing.c parsing_utils.c ray.c data_parser.c obj_filler.c camera.c rendering.c lighting.c\
   obj.c sphere.c debug.c plane.c cylinder.c isShadowed.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
DEPENDS = $(OBJS:.o=.d)
######################################################################
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -MMD -MP
LINK = -lmlx -lft -lm -lXext -lX11
INCPATH = -I$(INCDIR) -I$(FTINC) -I$(MLXPATH)
LIBPATH = -L$(FTPATH) -L$(MLXPATH)
NAME = miniRT
VAL = valgrind --leak-check=full ./$(NAME) input4.rt
RUN = ./$(NAME) input4.rt
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
