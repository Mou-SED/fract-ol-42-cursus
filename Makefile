# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:20:12 by moseddik          #+#    #+#              #
#    Updated: 2022/01/21 13:19:35 by moseddik         ###   ########.fr        #
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
SRCS = src/main.c src/fractals/mandelbrot.c src/fractals/julia.c src/events.c src/ft_utils.c src/fractals/burningShip.c src/coloring_output.c src/coloration.c

OBJ-DIR = src/obj-files
NAME = fractol
HEADER = -Iinclude

OBJS = ${SRCS:.c=.o}

%.o: %.c
	@$(CC) $(CLFAGS) -c $^ -o $@ ${HEADER}

${NAME}: ${OBJS}
	@$(CC) ${OBJS} $(CFLAGS) $(LDFLAGS) -o ${NAME} ${HEADER}
	@mkdir -p $(OBJ-DIR)
	@mv src/*.o $(OBJ-DIR)
	@mv src/fractals/*.o $(OBJ-DIR)

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
	@echo " 			$(GRAY)> ./fractol burningShip$(NONE)\n"
	 
	
all: ${NAME}

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