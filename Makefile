# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 10:05:58 by dhubleur          #+#    #+#              #
#    Updated: 2022/01/10 11:43:44 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			$(addprefix srcs/, \
				$(addprefix stack/, \
					parse.c \
					stack_util.c \
					stack_util2.c \
					stack_util3.c) \
				$(addprefix actions/, \
					stack_action_s.c \
					stack_action_p.c \
					stack_action_r.c \
					stack_action_rr.c) \
				$(addprefix sort/, \
					sort.c \
					big_sort.c \
					big_sort2.c \
					big_sort3.c \
					math_util.c))
OBJS	=	${SRCS:.c=.o}
INCL	=	-I./includes -I./libft 

NAME	=	push_swap
CC		=	gcc

#CFLAGS	=	-g3
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address

RM		=	rm -f

LIBFT	=	libft/libft.a

.c.o:
				${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ${LIBFT}
				${CC} -o ${NAME} ${OBJS} ${LIBFT}

$(LIBFT):
				$(MAKE) -C libft all

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

fcleanlib:	fclean
				make -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re fcleanlib
