NAME	:= minishell

CC		:= gcc
INCLUDE	:= ./include
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft/source
LIBFT	= libft
#FLAGS	= #-Wall
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
FLAGS = -I homebrew/opt/readline/include
SRCDIR	:= *.c
SRC		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR	:= ./obj
OBJ		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@$(CC) -g $(FLAGS) $(CFLAGS) $(READLINE) $(OBJ) libft.a -lreadline  -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) -c $< -o $@
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
