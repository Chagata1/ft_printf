# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryayla <ryayla@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 12:33:16 by ryayla            #+#    #+#              #
#    Updated: 2023/01/04 12:33:33 by ryayla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_utils.c
OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror


all :  ${NAME}

$(NAME) : ${OBJS}
	ar rc $(NAME) $(OBJS)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
