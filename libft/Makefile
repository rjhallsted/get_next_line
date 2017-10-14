#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 09:37:14 by rhallste          #+#    #+#              #
#    Updated: 2017/10/13 18:39:08 by rhallste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= 	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

P1_SRCS		=	ft_bzero					\
				ft_atoi						\
				ft_isalnum					\
				ft_isalpha					\
				ft_isascii					\
				ft_isdigit					\
				ft_islower					\
				ft_isspace					\
				ft_isprint					\
				ft_isupper					\
				ft_memccpy					\
				ft_memchr					\
				ft_memcmp					\
				ft_memcpy					\
				ft_memmove					\
				ft_memset					\
				ft_tolower					\
				ft_toupper					\
				ft_strcat					\
				ft_strchr					\
				ft_strcmp					\
				ft_strcpy					\
				ft_strdup					\
				ft_strlcat					\
				ft_strlen					\
				ft_strncat					\
				ft_strncmp					\
				ft_strncpy					\
				ft_strnstr					\
				ft_strrchr					\
				ft_strstr					
P2_SRCS		=	ft_itoa						\
				ft_memalloc					\
				ft_memdel					\
				ft_putchar					\
				ft_putchar_fd				\
				ft_putendl					\
				ft_putendl_fd	 			\
				ft_putnbr					\
				ft_putnbr_fd				\
				ft_putstr					\
				ft_putstr_fd				\
				ft_strclr					\
				ft_strdel					\
				ft_strequ					\
				ft_striter					\
				ft_striteri					\
				ft_strjoin					\
				ft_strmap					\
				ft_strmapi					\
				ft_strnequ					\
				ft_strnew					\
				ft_strsplit					\
				ft_strsub					\
				ft_strtrim					
B_SRCS		=	ft_free_2d_array			\
				ft_lst_itemcpy				\
				ft_lst_remove_if			\
				ft_lst_swap					\
				ft_lstadd					\
				ft_lstdel					\
				ft_lstdelone				\
				ft_lstdup					\
				ft_lstiter					\
				ft_lstlen					\
				ft_lstmap					\
				ft_lstnew					\
				ft_power					\
				ft_realloc					\
				ft_swap

SRCS		=	$(addsuffix .c, $(P1_SRCS) $(P2_SRCS) $(B_SRCS))
OBJS		=	$(addsuffix .o, $(P1_SRCS) $(P2_SRCS) $(B_SRCS))

all: $(NAME)

$(OBJS): $(SRCS)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.SILENT: $(OBJS)