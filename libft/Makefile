# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrosset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 14:58:27 by agrosset          #+#    #+#              #
#    Updated: 2017/05/21 14:58:14 by agrosset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra -I includes -c
SRCDIR		= ./
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
BUILDDIR	= ./build/
BUILDOBJS	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

GREEN		=	\033[32m
RED			=	\033[31m
DEFAULT		=	\033[37m

all: $(NAME)

# This won't run if the .o files don't exist or are not modified
$(NAME): $(BUILDOBJS)
	@ar rcs $(NAME) $(BUILDOBJS)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	@if ! [ -d "$(BUILDDIR)" ]; then mkdir $(BUILDDIR); fi
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "$(GREEN). $(DEFAULT)\c"

clean:
	@rm -rf $(BUILDDIR)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean:
	@$(MAKE) clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted for $(NAME)."

re:
	@$(MAKE) fclean
	@$(MAKE) all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re
