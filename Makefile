# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 05:44:54 by akunimot          #+#    #+#              #
#    Updated: 2024/04/30 04:53:12 by akunimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
			
SRCS 		= ft_printf.c \
			  ft_printf_csp.c \
			  ft_printf_diu.c \
			  ft_printf_x.c \

CC 			= cc
CFLAGS		= -Wall -Werror -Wextra
NAME 		= libftprintf.a
OBJS 		= $(SRCS:.c=.o)
LIBFT_MAKE	= $(MAKE) -C ./libft

all: $(NAME)

$(NAME): ${OBJS}
	${LIBFT_MAKE}
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o:            %.c
				$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	${RM} ${OBJS}
	${LIBFT_MAKE} clean

fclean: clean
	${RM} ${NAME}
	${LIBFT_MAKE} fclean

re: fclean all

.PHONY: all clean fclean re bonus