# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anazar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 10:07:33 by anazar            #+#    #+#              #
#    Updated: 2017/09/27 15:54:34 by anazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PART1 = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove \
		ft_memchr ft_memcmp ft_strcat ft_strchr ft_strcpy \
		ft_strdup ft_strlcat ft_strlen ft_strncat ft_strncpy \
		ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp \
		ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii \
		ft_isprint ft_toupper ft_tolower
PART2 = ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr \
		ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ \
		ft_strnequ ft_strsub ft_strtrim ft_strsplit ft_itoa \
		ft_putchar ft_putstr ft_putnbr ft_putendl ft_putchar_fd \
		ft_putstr_fd ft_putnbr_fd ft_putendl_fd ft_strjoin
BONUS = ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap
ADDIT = ft_iswhitespace ft_split_by_function ft_split_by_delims ft_swap \
		ft_isupper ft_islower ft_find_and_replace ft_find ft_trim_by_function \
		ft_trim_by_delims ft_atoll get_next_line ft_min ft_max ft_strjoinfree \
		ft_is_in ft_countif
FILES = $(PART1) $(PART2) $(BONUS) $(ADDIT)
MAINSRC = tst/main.c
MAINOBJ = main.o
TESTOUT = libtest
LIB = ar rc
FLAGS = -Wall -Werror -Wextra -I./includes/
SRCS = $(patsubst %, %.c, $(FILES))
OBJS = $(patsubst %, %.o, $(FILES))

all:	$(NAME)

test:
	@gcc $(FLAGS) -c $(SRCS) $(MAINSRC) ./libft.h
	@gcc $(OBJS) $(MAINOBJ) -o $(TESTOUT)
	@$(MAKE) clean
	@rm -rf *.gch

tclean:
	@rm -rf $(TESTOUT)

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS) $(MAINOBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
