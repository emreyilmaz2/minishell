NAME= mini
CC = gcc
C_FILES = $(wildcard ./ft_*.c)
OBJ = $(C_FILES:.c=.o)
flags = -I /goinfre/homebrew/opt/readline/include
readline = -lreadline -L /goinfre/homebrew/opt/readline/lib
#-Wall -Werror -Wextra 
OBJ =   $(C_FILES:.c=.o)
.c.o:
	$(CC) $(flags) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME) : $(OBJ) minishell.h
	$(CC) $(flags) $(readline) $(OBJ) -o $(NAME)

clean:
	@echo "\033[0;32mcleaned"
	@rm -rf *.o
	@rm -f $(NAME) 
re : clean all
.PHONY:clean all re