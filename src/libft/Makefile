# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skgatle <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/14 07:24:17 by skgatle           #+#    #+#              #
#    Updated: 2017/07/23 06:29:17 by skgatle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft.a
CFILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memcpy.c\
ft_memchr.c ft_memcmp.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putchar_fd.c ft_putnbr.c\
ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c\
ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
ft_strnequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
ft_toupper.c ft_strmap.c ft_strmapi.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
ft_lstadd.c ft_lstiter.c ft_wcslen.c ft_wcputstr.c ft_del_link.c\
get_next_line.c ft_lstmap.c ft_strlenc.c ft_2dfree.c ft_search_alnum_end.c\
ft_skip_spaces.c

OBJ = $(CFILES:.c=.o);

all: $(NAME)

$(NAME): $(CFILES)
	@$(CC) $(CFLAGS)  $(CFILES)
	@ar -cr $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
