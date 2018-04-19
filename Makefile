# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anazar <anazar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 10:07:33 by anazar            #+#    #+#              #
#    Updated: 2017/12/26 15:42:58 by anazar           ###   ########.fr        #
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
		ft_trim_by_delims ft_atoll get_next_line ft_strjoinfree \
		ft_is_in ft_countif ft_strfncpy ft_strrncpy ft_validate
MAINFILES = $(PART1) $(PART2) $(BONUS) $(ADDIT)
PRINTFILES = ft_printf get_format generate_table get_width \
		set_type set_output set_tmp fix_sign handle \
		utils check parse_utils1 parse_utils2 ft_jtoa \
		ft_jutoa ft_ctos ft_wctos
PRINTFDIR = printf/
MAINDIR = src/
SRCFILES = $(addprefix $(PRINTFDIR), $(PRINTFILES)) $(addprefix $(MAINDIR), $(MAINFILES))
FILES = $(PRINTFILES) $(MAINFILES)
MAINSRC = tst/main.c
MAINOBJ = main.o
TESTOUT = libtest
LIB = ar rc
FLAGS = -Wall -Werror -Wextra -I./includes/
SRCS = $(patsubst %, %.c, $(SRCFILES))
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
