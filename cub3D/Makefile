CC = cc

LIBX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
LIBFT = -Llibft -lft

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	layer_1/map.c layer_1/player.c layer_1/raycaster.c \
	layer_2/update_vision.c layer_2/update_player.c layer_2/update_game.c \
	layer_4/mlx_controller.c layer_4/mlx_displayer.c \
	layer_4/mlx_close.c layer_4/mlx_init.c layer_4/mlx_event.c

HEADERS = layer_1/map.h layer_1/player.h layer_1/raycaster.h \
	layer_2/update_vision.h layer_2/update_player.h layer_2/update_game.h \
	layer_3/controller.h layer_3/displayer.h \
	layer_4/mlx_context.h layer_4/mlx_controller.h layer_4/mlx_displayer.h

BUILD_DIR = build
# Liste des fichiers objets avec le répertoire build
OBJ_FILES = $(SRC:srcs/%.c=$(BUILD_DIR)/%.o)

NAME = $(BUILD_DIR)/cub3d

# Règle par défaut pour créer l'exécutable
all: lib create-dir $(NAME) 

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBX) $(LIBFT) -o $(NAME)

# Règle pour compiler un fichier .c en .o dans build/
$(BUILD_DIR)/%.o: srcs/%.c $(HEADERS)
	$(CC) -c $< -o $@

# Nettoyage des fichiers objets dans build/
lib:
	@make -C libft > /dev/null 2>&1
	@make -C minilibx-linux > /dev/null 2>&1
	
create-dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJ_FILES)

# Nettoyage complet (objets + exécutable dans build/)
fclean: clean
	rm -f $(NAME)

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
