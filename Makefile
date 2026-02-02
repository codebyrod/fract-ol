# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 07:25:17 by rosousa-          #+#    #+#              #
#    Updated: 2026/02/02 10:56:46 by rosousa-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 1. Nomes e Caminhos
NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
MLX_DIR     = ./minilibx-linux
MLX_LNK     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# 2. Arquivos (Adicione seus .c aqui)
SRC         = main.c \
              init.c \
              render.c \
              math_utils.c \
              events.c \
              error.c \
              string_utils.c \
              parse.c \

OBJ         = $(SRC:.c=.o)

# 3. Cores para o terminal (Opcional, mas ajuda na visualização)
GREEN       = \033[0;32m
RESET       = \033[0m

# 4. Regras Principais
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LNK) -o $(NAME)
	@echo "$(GREEN)Fract-ol compilado com sucesso!$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	@make -C $(MLX_DIR) clean
	rm -f $(OBJ)
	@echo "Objetos removidos."

fclean: clean
	rm -f $(NAME)
	@echo "Executável removido."

re: fclean all

.PHONY: all clean fclean re