USERNAME= emyilmaz
NAME	:= minishell
CC		:= gcc
INCLUDE	:= ./include -I/Users/emyilmaz/goinfre/homebrew/Cellar/readline/8.2.1/include 
CFLAGS	:= -ggdb -I $(INCLUDE)
LIBFT	= libft
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
FLAGS = -Wall -Werror -Wextra
SRCDIR	:= *.c
SRC		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR	:= ./obj
OBJ		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	$(CC) -g $(CFLAGS) $(FLAGS) $(READLINE) $(OBJ) libft.a -lreadline  -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -g $(CFLAGS) -c $< -o $@
	echo "cleaned"

clean:
	@make clean -C $(LIBFT)
	@rm -rf libft.a
	@rm -rf $(OBJDIR)

fclean:
	@make fclean -C $(LIBFT)
	@rm -rf libft.a
	@rm -rf $(OBJDIR)
	@rm -rf *.o
	@rm -f $(NAME)

re:	fclean all

#credit:
#	@echo "		███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
#	@echo "		████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
#	@echo "		██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
#	@echo "		██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
#	@echo "		██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
#	@echo "		╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
#	@echo "		      Made with love by : \033[1;91memyilmaz\033[m and \033[1;91mataskin\033[m"

.PHONY: fclean clean all re
