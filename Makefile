# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 11:50:09 by allauren          #+#    #+#              #
#    Updated: 2017/11/27 20:53:22 by allauren         ###   ########.fr        #
#                                                                              #
SRCS = options.c print_numbers.c string.c   utils.c utils2.c\
	   ft_itoabase.c  parsing.c  printf.c stritostr.c 
SRCS2 = options.c print_numbers.c string.c   utils.c utils2.c\
	   ft_itoabase.c main.c  parsing.c  printf.c stritostr.c 

CFLAGS =-g3 -c -Wall -Wextra -Werror
FLAGS  = -g3 -Wall -Wextra 
TEST = printf
INCLUDES = printf.h
CC = gcc
LN = ar
LFLAGS = rc
LIBOPTIMIZER = ranlib
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFT = libft/libft.a

all: $(NAME)
$(NAME): $(LIBFT) $(OBJS) $(INCLUDES)
	@printf "\r\033[K[PRINTF] \033[0;32mLinking...\033[0m"
	@cp $(LIBFT) $(NAME)
	@$(LN) $(LFLAGS) $(NAME) $(OBJS)
	@printf "\r\033[K[PRINTF] \033[0;32mDone!\033[0m\n"
$(LIBFT):
	@$(MAKE) -C libft/
%.o: %.c
	@printf "\r\033[K[PRINTF] \033[0;32mBuilding $<\033[0m"
	@$(CC) $(CFLAGS) $< -o $@
test: 
	gcc $(FLAGS) $(SRCS2) $(LIBFT) -o $(TEST)
clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)
	@printf "[PRINTF] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	@printf "[PRINTF] \033[1;31mCleaned all!\033[0m\n"
re: fclean all
.PHONY: all clean fclean re
	# **************************************************************************** #
