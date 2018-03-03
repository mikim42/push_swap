# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 20:59:08 by mikim             #+#    #+#              #
#    Updated: 2017/10/28 22:29:11 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = init_psenv.c init_psflag.c init_inst.c destroyer.c message.c \
	  print_stack.c print_push.c print_swap.c print_rotate.c print_reverse.c \
	  opt_push.c opt_swap.c opt_rotate.c opt_reverse.c 

SRC_CHK = checker.c check_stack.c run_checker.c
	  
SRC_PS = push_swap.c run_push_swap.c parse_stack.c\
		 check_sorted.c write_inst.c get_minimum_op.c\
		 check_push_swap.c check_rotate.c check_reverse.c check_rrrrr.c\
		 check_cross.c

SRC_RAND = rand_gen.c
	  
OBJ = $(SRC:.c=.o)
OBJ_CHK = $(SRC_CHK:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)
OBJ_RAND = $(SRC_RAND:.c=.o)

SRCDIR = srcs
SRCDIR_CHK = srcs_chk
OBJDIR_CHK = objs_chk
SRCDIR_PS = srcs_ps
OBJDIR_PS = objs_ps
SRCDIR_RAND = srcs_rand
OBJDIR_RAND = objs_rand
LIBDIR = libft

SRCS_CHK = $(addprefix $(SRCDIR_CHK)/, $(SRC_CHK)) \
		   $(addprefix $(SRCDIR)/, $(SRC))
OBJS_CHK = $(addprefix $(OBJDIR_CHK)/, $(OBJ_CHK)) \
		   $(addprefix $(OBJDIR_CHK)/, $(OBJ))

SRCS_PS = $(addprefix $(SRCDIR_PS)/, $(SRC_PS)) \
		  $(addprefix $(SRCDIR)/, $(SRC))
OBJS_PS = $(addprefix $(OBJDIR_PS)/, $(OBJ_PS)) \
		  $(addprefix $(OBJDIR_PS)/, $(OBJ))

SRCS_RAND = $(addprefix $(SRCDIR_RAND)/, $(SRC_RAND))
OBJS_RAND = $(addprefix $(OBJDIR_RAND)/, $(OBJ_RAND))

LIBS = -L $(LIBDIR) -lft
HEADER = -I includes -I $(LIBDIR)/includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME_CHK = checker
NAME_PS = push_swap
NAME_RAND = rand_generator

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME_CHK) $(NAME_PS) $(NAME_RAND)

#COMPILING CHECKER
$(OBJDIR_CHK)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR_CHK)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(OBJDIR_CHK)/%.o: $(SRCDIR_CHK)/%.c
	@mkdir -p $(OBJDIR_CHK)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@


$(NAME_CHK): $(OBJS_CHK)
	@make -C $(LIBDIR)
	@$(CC) $(OBJS_CHK) $(HEADER) $(LIBS) -o $@
	@echo "[Checker - 모래반지 빵야빵야!]"

#COMPILING PUSH_SWAP
$(OBJDIR_PS)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR_PS)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(OBJDIR_PS)/%.o: $(SRCDIR_PS)/%.c
	@mkdir -p $(OBJDIR_PS)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME_PS): $(OBJS_PS)
	@$(CC) $(OBJS_PS) $(HEADER) $(LIBS) -o $@
	@echo "[Push_swap - 모래반지 빵야빵야!]"

#COMPILING RAND_GENERATOR
$(OBJDIR_RAND)/%.o: $(SRCDIR_RAND)/%.c
	@mkdir -p $(OBJDIR_RAND)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME_RAND): $(OBJS_RAND)
	@$(CC) $(OBJS_RAND) $(HEADER) $(LIBS) -o $@
	@echo "[Rand_gen - 모래반지 빵야빵야!]"

clean:
	@/bin/rm -rf $(OBJDIR_CHK)
	@/bin/rm -rf $(OBJDIR_PS)
	@/bin/rm -rf $(OBJDIR_RAND)
	@make -C $(LIBDIR) clean
	@echo "[Push_swap - clean]"

fclean:
	@/bin/rm -rf $(OBJDIR_CHK)
	@/bin/rm -rf $(OBJDIR_PS)
	@/bin/rm -rf $(OBJDIR_RAND)
	@/bin/rm -f $(NAME_CHK)
	@/bin/rm -f $(NAME_PS)
	@/bin/rm -f $(NAME_RAND)
	@make -C $(LIBDIR) fclean
	@echo "[Push_swap - fclean]"

re: fclean all
