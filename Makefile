# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:20:12 by moseddik          #+#    #+#              #
#    Updated: 2022/10/06 11:32:46 by moseddik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NONE=\033[0m
GREEN=\033[32m
YELLOW=\033[33m
GRAY=\033[2;37m
CURSIVE=\033[3m
RED =\033[0;31m
BLUE =\033[0;34m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -Ofast  -framework OpenGL -framework AppKit
SRCS = src/main.c \
		src/events.c \
		src/ft_utils.c \
		src/coloring_output.c \
		src/coloration.c
FRACTAL_SRCS = src/fractals/mandelbrot.c \
				src/fractals/julia.c \
				src/fractals/burningShip.c

OBJ-DIR = src/obj-files
NAME = fractol
HEADER = -I include

OBJS = $(patsubst src/%.c, src/obj-files/%.o, $(SRCS)) \
		$(patsubst src/fractals/%.c, src/obj-files/%.o, $(FRACTAL_SRCS))

all: ${NAME}

src/obj-files/%.o: src/%.c | $(OBJ-DIR)
	@$(CC) $(CLFAGS) -c $^ -o $@ ${HEADER}

src/obj-files/%.o: src/fractals/%.c | $(OBJ-DIR)
	@$(CC) $(CLFAGS) -c $^ -o $@ ${HEADER}

$(OBJ-DIR):
	@mkdir -p $@

${NAME}: ${OBJS}
	@$(CC) ${OBJS} $(CFLAGS) $(LDFLAGS) -o ${NAME} ${HEADER}
	@echo ""
	@echo " $(BLUE)Wᴇʟᴄᴏᴍᴇ ᴛᴏ ᴍʏ$(NONE)\n"
	@sleep 0.6
	@echo "		$(RED)▒█▀▀▀ ▒█▀▀█ ░█▀▀█ ▒█▀▀█ ▀▀█▀▀ ▒█▀▀▀█ ▒█░░░$(NONE)	"
	@sleep 0.2
	@echo "		$(RED)▒█▀▀▀ ▒█▄▄▀ ▒█▄▄█ ▒█░░░ ░▒█░░ ▒█░░▒█ ▒█░░░$(NONE)	"
	@sleep 0.2
	@echo "		$(RED)▒█░░░ ▒█░▒█ ▒█░▒█ ▒█▄▄█ ░▒█░░ ▒█▄▄▄█ ▒█▄▄█$(NONE)	\n"
	@sleep 1
	@echo "                                            $(YELLOW)𝔸𝕣𝕖 𝕪𝕠𝕦 𝕣𝕖𝕒𝕕𝕪❕$(NONE)"
	@echo ""
	@echo " 		$(GRAY)To use this program, simply start the fractol file and put the name of the fractol you want to see!$(NONE)\n"
	@echo " 		$(GRAY)Like this:$(NONE)\n"
	@echo " 			$(GRAY)> ./fractol mandelbrot$(NONE)"
	@echo " 			$(GRAY)> ./fractol julia$(NONE)"
	@echo " 			$(GRAY)> ./fractol burningship$(NONE)\n"


clean:
	@rm -rf $(OBJ-DIR)
	@echo ""
	@echo "		$(RED)╭━━┳╮╱╱╭╮$(NONE)"
	@echo "		$(RED)┃╭╮┃╰╮╭╯┃$(NONE)"
	@echo "		$(RED)┃╰╯╰╮╰╯╭╯$(NONE)"
	@echo "		$(RED)┃╭━╮┣╮╭╯$(NONE)"
	@echo "		$(RED)┃╰━╯┃┃┃$(NONE)"
	@echo "		$(RED)╰━━━╯╰╯$(NONE)"
	@sleep 0.5
	@echo "                $(BLUE)--------$(NONE)"

fclean:	clean
	@rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re