# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 09:44:56 by mikim             #+#    #+#              #
#    Updated: 2017/07/31 21:34:56 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_intlen.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_atoi_base.c\
	ft_atol.c\
	ft_atoll.c\
	ft_abs.c\
	ft_min.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_upcase.c\
	ft_lowcase.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strcjoin.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_itoa_base.c\
	ft_ltoa.c\
	ft_ltoa_base.c\
	ft_lltoa.c\
	ft_lltoa_base.c\
	ft_uns_itoa.c\
	ft_uns_ltoa.c\
	ft_uns_lltoa.c\
	ft_uns_itoa_base.c\
	ft_uns_ltoa_base.c\
	ft_uns_lltoa_base.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_create_elem.c\
	ft_list_push_back.c\
	ft_list_push_front.c\
	ft_list_clear.c\
	btree_create_node.c\
	btree_apply_prefix.c\
	btree_apply_infix.c\
	btree_apply_suffix.c\
	get_next_line.c\
	ft_printf.c\
	parse_args.c\
	parse_spec.c\
	init_args.c\
	init_args_etc.c\
	print_spec.c\
	print_spec_etc.c\
	print_char.c\
	print_str.c\
	print_wchar.c\
	print_wstr.c\
	print_digit.c\
	print_base.c\
	print_prec_a.c\
	print_prec_e.c\
	print_prec_f.c\
	print_prec_g.c\
	print_ptraddr.c\
	print_invalid.c\
	print_non_printable.c\
	print_prec_tools.c\
	print_dice.c\
	settings.c

OBJ = $(SRC:.c=.o)

SRCDIR = srcs

OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = -I includes

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libft.a

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(OBJDIR):
	@/bin/mkdir -p $(OBJDIR)

$(OBJS): | $(OBJDIR)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@ranlib $@
	@echo "[libft - 모래반지 빵야빵야!]"

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[libft - clean]"

fclean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -f $(NAME)
	@echo "[libft - fclean]"

re: fclean all
