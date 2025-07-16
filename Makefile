# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 10:00:00 by sabejaou          #+#    #+#              #
#    Updated: 2024/05/30 10:00:00 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
LIBMLX_DIR = libmlx

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR)
LIBS = -L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR) -lmlx -lm -lXext -lX11

all: libft libmlx $(NAME)

$(NAME): $(OBJS)
	@echo "Edition des liens..."
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)
	@echo "Binaire $(NAME) créé avec succès !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "Compilation de $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

libmlx:
	@$(MAKE) -C $(LIBMLX_DIR)

clean:
	@echo "Nettoyage des fichiers objets..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBMLX_DIR) clean
	@echo "Nettoyage terminé !"

fclean: clean
	@echo "Nettoyage complet..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBMLX_DIR) clean
	@echo "Nettoyage complet terminé !"

re: fclean all

run: all
	./$(NAME) test_maps/42.fdf

.PHONY: all clean fclean re libft libmlx run 