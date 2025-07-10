CC = cc

LIBX = -Llayer_5/lib/minilibx-linux -lmlx_Linux -lX11 -lXext -lm
LIBFT = -Llayer_5/lib/libft -lft

INCLUDES = \
	-Ilayer_1/map \
	-Ilayer_1/player \
	-Ilayer_1/raycaster \
	-Ilayer_2/update_position \
	-Ilayer_2/update_vision \
	-Ilayer_3 \
	-Ilayer_4/mlx_controller \
	-Ilayer_4/mlx_controller/mlx_controller_function \
	-Ilayer_4/mlx_controller/mlx_input \
	-Ilayer_4/mlx_displayer \
	-Ilayer_4/mlx_displayer/mlx_displayer_init \
	-Ilayer_4/mlx_displayer/mlx_displayer_function \
	-Ilayer_4/mlx_displayer/mlx_displayer_function/mlx_display_env \
	-Ilayer_4/mlx_main \
	-Ilayer_4/game \
	-Ilayer_5/lib/libft \
	-Ilayer_5/lib/minilibx-linux

CFLAGS = -g -MMD -MP $(INCLUDES) 
 #/*-Wall -Wextra -Werror*/
SRC = layer_main/main.c\
	layer_1/map/map.c \
	layer_1/player/player_camera.c \
	layer_1/player/player_helper.c \
	layer_1/player/player_moove.c \
	layer_1/raycaster/raycaster.c \
	layer_1/raycaster/raycaster_init.c \
	layer_1/raycaster/raycaster_multiple.c \
	layer_2/update_position/update_position.c \
	layer_2/update_vision/update_vision.c \
	layer_4/game/start_game.c \
	layer_4/mlx_controller/mlx_controller_function/mlx_move.c \
	layer_4/mlx_controller/mlx_controller_function/mlx_rotation.c \
	layer_4/mlx_controller/mlx_controller_init/mlx_init_controller.c \
	layer_4/mlx_controller/mlx_input/mlx_press.c \
	layer_4/mlx_controller/mlx_input/mlx_release.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_env/mlx_display_env.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_env/mlx_display_env_tool.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_displayer_tool.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_minimap.c \
	layer_4/mlx_displayer/mlx_displayer_init/mlx_displayer_init_main.c \
	layer_4/mlx_displayer/mlx_displayer_init/mlx_displayer_init_minimap_and_color.c \
	layer_4/mlx_displayer/mlx_displayer_init/mlx_displayer_init_texture.c \
	layer_4/mlx_main/mlx_close.c \
	layer_4/mlx_main/mlx_main_init.c

HEADERS = \
	-Ilayer_1/map/map.h \
	-Ilayer_1/player/player.h \
	-Ilayer_1/raycaster/raycaster.h \
	-Ilayer_2/update_position/update_position.h \
	-Ilayer_2/update_vision/update_vision.h \
	-Ilayer_3/interface_displayer.h \
	-Ilayer_3/interface_controller.h \
	-Ilayer_3/interface_file_reader.h \
	-Ilayer_4/mlx_controller/mlx_controller.h \
	-Ilayer_4/mlx_main/mlx_context.h \
	-Ilayer_4/mlx_displayer/mlx_displayer.h \
	-Ilayer_4/mlx_displayer/mlx_displayer_init/mlx_displayer_init.h \
	-Ilayer_4/mlx_displayer/mlx_displayer_function/mlx_displayer_function.h \
	-Ilayer_4/game/game_context.h \
	-Ilayer_5/lib/libft/ft_printf.h \
	-Ilayer_5/lib/libft/libft.h \
	-Ilayer_5/lib/minilibx-linux/mlx.h \
	-Ilayer_5/lib/minilibx-linux/mlx_int.h 

BUILD_DIR = build
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
DEP_FILES = $(OBJ_FILES:.o=.d)

NAME = $(BUILD_DIR)/cub3d

# Default target
all: lib create-dir $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBX) $(LIBFT) -o $(NAME)

# Compile .c files to .o inside build/
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	@make -C layer_5/lib/libft > /dev/null 2>&1
	@make -C layer_5/lib/minilibx-linux > /dev/null 2>&1

create-dir:
	@mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib create-dir

# Include dependency files if they exist
-include $(DEP_FILES)