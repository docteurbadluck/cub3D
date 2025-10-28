CC = cc

LIBX = -Llayer_5/lib/minilibx-linux -lmlx_Linux -lX11 -lXext -lm
LIBFT = -Llayer_5/lib/libft -lft

INCLUDES = \
	-Ilayer_1/map \
	-Ilayer_1/player \
	-Ilayer_1/raycaster \
	-Ilayer_1/sprite \
	-Ilayer_2/update_position \
	-Ilayer_2/update_vision \
	-Ilayer_2/update_sprite \
	-Ilayer_3 \
	-Ilayer_4/mlx_controller \
	-Ilayer_4/mlx_controller/mlx_controller_function \
	-Ilayer_4/mlx_controller/mlx_input \
	-Ilayer_4/mlx_displayer \
	-Ilayer_4/mlx_displayer/mlx_displayer_init \
	-Ilayer_4/mlx_displayer/mlx_displayer_function \
	-Ilayer_4/mlx_displayer/mlx_displayer_function/mlx_display_env \
	-Ilayer_4/mlx_displayer/mlx_displayer_function/mlx_display_sprites \
	-Ilayer_4/mlx_main \
	-Ilayer_4/parsing \
	-Ilayer_4/game \
	-Ilayer_4/includes \
	-Ilayer_5/lib/libft \
	-Ilayer_5/lib/minilibx-linux

CFLAGS = -g -MMD -MP -Wall -Wextra -Werror $(INCLUDES)
CFLAGS_TEST = -g $(INCLUDES)

SRC = layer_main/main.c\
	layer_1/map/map.c \
	layer_1/player/player_rotate.c \
	layer_1/player/player_helper.c \
	layer_1/player/player_moove.c \
	layer_1/raycaster/raycaster.c \
	layer_1/raycaster/raycaster_init.c \
	layer_1/raycaster/raycaster_player_view.c \
	layer_1/sprite/update_sprites_data.c \
	layer_1/sprite/sprite_helper.c \
	layer_1/sprite/create_sprite_from_map.c \
	layer_2/update_position/update_position.c \
	layer_2/update_vision/update_vision.c \
	layer_2/update_sprite/update_sprite.c \
	layer_4/game/start_game.c \
	layer_4/game/start_game_loop.c \
	layer_4/game/game_initialisation.c \
	layer_4/game/game_initialisation_helper.c \
	layer_4/game/player_and_map_init.c \
	layer_4/mlx_controller/mlx_controller_function/mlx_move.c \
	layer_4/mlx_controller/mlx_controller_function/mlx_rotation.c \
	layer_4/mlx_controller/mlx_controller_init/mlx_create_controller.c \
	layer_4/mlx_controller/mlx_input/mlx_press.c \
	layer_4/mlx_controller/mlx_input/mlx_release.c \
	layer_4/mlx_controller/mlx_input/mlx_mouse_moove.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_env/mlx_display_env.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_env/mlx_display_env_tool.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_displayer_tool.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_minimap.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_sprites/mlx_sprites.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_sprites/mlx_sprites_tool.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_sprites/mlx_sprites_texture_tool.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_sprites/mlx_draw_sprite.c \
	layer_4/mlx_displayer/mlx_displayer_function/mlx_display_sprites/mlx_animate_sprite.c \
	layer_4/mlx_displayer/mlx_displayer_init/mlx_create_displayer.c \
	layer_4/mlx_displayer/mlx_displayer_init/mlx_displayer_init_minimap_and_color.c \
	layer_4/mlx_displayer/mlx_displayer_init/mlx_displayer_init_texture.c \
	layer_4/mlx_displayer/mlx_displayer_init/mlx_displayer_init_sprites.c \
	layer_4/mlx_main/mlx_close.c \
	layer_4/mlx_main/mlx_close_helper.c \
	layer_4/mlx_main/mlx_main_init.c \
	layer_4/parsing/0_start.c \
	layer_4/parsing/1_file_format.c \
	layer_4/parsing/color_utils.c \
	layer_4/parsing/extract_utils.c \
	layer_4/parsing/flood_fill.c \
	layer_4/parsing/free_functions.c \
	layer_4/parsing/flood_fill_utils.c \
	layer_4/parsing/grid_utils.c \
	layer_4/parsing/map_building.c \
	layer_4/parsing/texture_logic.c \
	layer_4/parsing/texture_check.c \
	layer_4/parsing/texture_parsing.c \
	layer_4/parsing/utils.c \
	layer_4/parsing/validation_utils.c 

HEADERS = \
	-Ilayer_1/map/map.h \
	-Ilayer_1/player/player.h \
	-Ilayer_1/raycaster/raycaster.h \
	-Ilayer_1/sprite/sprite.h \
	-Ilayer_2/update_position/update_position.h \
	-Ilayer_2/update_vision/update_vision.h \
	-Ilayer_2/update_vision/frame_buffer.h \
	-Ilayer_2/update_sprite/update_sprite.h \
	-Ilayer_2/update_sprite/sprite_buffer.h \
	-Ilayer_3/interface_displayer.h \
	-Ilayer_3/interface_controller.h \
	-Ilayer_3/interface_file_reader.h \
	-Ilayer_4/mlx_controller/mlx_controller.h \
	-Ilayer_4/mlx_main/mlx_context.h \
	-Ilayer_4/mlx_displayer/mlx_displayer.h \
	-Ilayer_4/mlx_displayer/mlx_displayer_init/mlx_displayer_init.h \
	-Ilayer_4/mlx_displayer/mlx_displayer_function/mlx_displayer_function.h \
	-Ilayer_4/mlx_displayer/mlx_displayer_function/mlx_display_sprites/mlx_sprites.h \
	-Ilayer_4/game/game.h \
	-Ilayer_4/parsing.h \
	-Ilayer_4/includes/init_data.h \
	-Ilayer_5/lib/libft/ft_printf.h \
	-Ilayer_5/lib/libft/libft.h \
	-Ilayer_5/lib/minilibx-linux/mlx.h \
	-Ilayer_5/lib/minilibx-linux/mlx_int.h 


BUILD_DIR = build
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
DEP_FILES = $(OBJ_FILES:.o=.d)

MAIN_SRC = layer_main/main.c
SRC_NO_MAIN = $(filter-out $(MAIN_SRC), $(SRC))

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
	rm -f $(DEP_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib create-dir test

# Include dependency files if they exist
-include $(DEP_FILES)