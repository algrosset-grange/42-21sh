# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 16:47:55 by agrosset          #+#    #+#              #
#    Updated: 2018/07/21 16:47:59 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCDIR = ./src/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./inc/
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

all: $(LIBFT) $(NAME)


$(BUILDDIR)%.o:$(SRCDIR)%.c
	@if ! [ -d "$(BUILDDIR)" ]; then mkdir $(BUILDDIR); fi
	@$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<
	@echo "$(GREEN). $(DEFAULT)\c"

$(NAME): $(BUILDOBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LIBFT)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

clean:
	@rm -rf $(BUILDDIR)
	@$(MAKE) -C $(LIBDIR) fclean
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean:
	@rm -rf $(BUILDDIR)
	@$(MAKE) -C $(LIBDIR) fclean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all fclean clean re
