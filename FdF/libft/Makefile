# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fciocan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/16 12:05:25 by fciocan           #+#    #+#              #
#    Updated: 2018/02/08 17:43:10 by fciocan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB = ./includes/

FLAGS = -Wall -Werror -Wextra

SRCFILES = ft_memccpy.c ft_putnbr.c ft_sqrt.c ft_strequ.c ft_strnequ.c ft_memchr.c ft_putnbr_fd.c ft_striter.c ft_strnew.c ft_atoi.c ft_memcmp.c ft_putstr.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c ft_isalnum.c ft_memdel.c ft_strcat.c ft_strlcat.c ft_strsplit.c ft_isalpha.c ft_memmove.c ft_strchr.c ft_strlen.c ft_strstr.c ft_isascii.c ft_memset.c ft_strclr.c ft_strmap.c ft_strsub.c ft_isdigit.c ft_putchar.c ft_strcmp.c ft_strmapi.c ft_strtrim.c ft_isprint.c ft_putchar_fd.c ft_strcpy.c ft_strncat.c ft_tolower.c ft_itoa.c ft_putendl.c ft_strdel.c ft_strncmp.c ft_toupper.c ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_swap.c ft_strcapitalize.c ft_str_is_uppercase.c ft_str_is_lowercase.c ft_list_size.c get_next_line.c

OBJECT =	$(SRCFILES:.c=.o)

all: $(NAME)

$(NAME):
		gcc -c $(FLAGS) -I $(LIB) $(SRCFILES)
		ar rc $(NAME) $(OBJECT)

clean:
		/bin/rm -f $(OBJECT)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
		gcc -c $(FLAGS) -I $(LIB) $(SRCFILES)
		ar rc $(NAME) $(OBJECT)
