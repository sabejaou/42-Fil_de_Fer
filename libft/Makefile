# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 15:56:34 by sabejaou          #+#    #+#              #
#    Updated: 2024/02/13 13:28:07 by sabejaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_memset.c     			\
		ft_isalnum.c    			\
		ft_isprint.c    			\
		ft_memcpy.c     			\
		ft_putendl_fd.c 			\
		ft_strchr.c     			\
		ft_strlcat.c    			\
		ft_strncmp.c    			\
		ft_substr.c     			\
		ft_atoi.c       			\
		ft_isalpha.c    			\
		ft_itoa.c       			\
		ft_memmove.c    			\
		ft_putnbr_fd.c  			\
		ft_strdup.c     			\
		ft_strlcpy.c    			\
		ft_strnstr.c    			\
		ft_tolower.c    			\
		ft_bzero.c      			\
		ft_isascii.c    			\
		ft_memchr.c     			\
		ft_memset.c     			\
		ft_putstr_fd.c  			\
		ft_striteri.c   			\
		ft_strlen.c     			\
		ft_strrchr.c    			\
		ft_toupper.c    			\
		ft_calloc.c     			\
		ft_isdigit.c    			\
		ft_memcmp.c     			\
		ft_putchar_fd.c 			\
		ft_split.c      			\
		ft_strjoin.c    			\
		ft_strmapi.c    			\
		ft_strtrim.c 				\
		ft_lstadd_back.c			\
		ft_lstadd_front.c			\
		ft_lstclear.c				\
		ft_lstdelone.c				\
		ft_lstiter.c				\
		ft_lstlast.c				\
		ft_lstmap.c					\
		ft_lstnew.c					\
		ft_lstsize.c				\
		get_next_line.c				\
		get_next_line_utils.c		\
			
OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o : %.c libft.h
	${CC} ${FLAGS} -I includes -c $< -o $@

$(NAME): ${OBJS} 
	ar rc ${NAME} ${OBJS}

all: ${NAME} 

clean:
ifneq ("$(wildcard $(OBJS))","")
	${RM} ${OBJS}
endif

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re