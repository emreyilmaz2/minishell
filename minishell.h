/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:13:43 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/25 10:03:55 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
// #include <homebrew/opt/readline/lib>
// #include "../../homebrew/bin/homebrew/opt/readline/lib"
#include "libft/source/libft.h"


typedef struct ss_list
{
	char 	*data;
	struct 	ss_list *next;
	struct 	ss_list *prev;
}			t_mini;

typedef struct s_env
{
	t_mini	*g_env_list;
	char	**export;
	int		exit_status;
	char	**environment;
	int		sayac;
	char	*name;
}	t_env;

extern t_env	*g_list;


typedef struct ss_data
{
	char **str;    //bölünmüş command
	char *data;   //full command
	char *name;

}		t_data;

typedef struct s_expander
{
	char **env_head;
	char **env_tail;
	char *temp_head;
	char *temp;
	char *temp_tail;
	char *src;
	char **changed_env;
}			t_expander;

typedef struct s_main_list
{
	char 	*pipe_cmd;
	char	*path;
	int		*infile_fd_r;
	int		*infile_fd_l;
	char	**infile_name_l; //bunları çift boyutlu yapmam lazım birden fazla redir gelebilir
	char 	**infile_name_r;
	int		*outfile_fd_r;
	int		*outfile_fd_l;
	char	**outfile_name_l;
	char	**outfile_name_r;//             "                         " 
	char	*eof;
	int		eof_fd;
	int		*append_fd_r;
	int		*append_fd_l;	//fdleri sonra doldurmak daha mantıklı çünkü böyle yaparsam dosyaları iki kere açmış olabilirim bu da kötü olur. sadece isimleri tutup diğer fonksiyonlarda açıp işlemi yapıp kapatmak gerekiyor.
	char	**append_r;
	char	**append_l;
	char	**args;
	char	*cmd;
	char 	*flag;
	char	**two_d_cmd;
	struct s_main_list *next;
	int std_out;
}	t_main_list;


//functions for lexer
int		checker(char *str);
int		counter(char *input);
int		counter2(char **input);
int		ft_check(char *str);
int		left_right(char *input, int *j, int flag);
int		ft_check_quotes(char *str);
int		ft_compare(char *str, int i);
char	**ft_array_copy_stuff(char *array, char **temp, int *y, int flag);
char	**ft_character_copy_stuff(char **temp, char *str , int *i, int *y);
char	**monster_truck(char *str, int i, int j, int y);
char	**this_is_not_split(char **string, int len, int j, int r);
char	**temproray_copy(char ***temp, char **daft, int r, int *j);
void	convert_space(char *str);

//functions for expander
void	expander_trim_dquote(t_mini ***list_two, t_expander ***exp);
void	expander_trim_squote(t_mini **list_two, t_expander **expander);
void check_greens(t_mini **lst2,t_expander **exp);
void	expander_uptade(t_mini *lst2, t_expander *exp);
void no_greens(t_mini ***lst2);
void	expander_trim_dquote_norm(t_expander ****exp, char **arr);
t_expander	*expander(t_mini *list);


//functions for cmd
void	find_cmd(t_main_list *m_list);
void	fill_it_all(char **array, char ****all_path, t_main_list *m_list);
void	trying_find_cmd(t_main_list **m_list, char ***all_path);

void	ft_export(t_main_list *m_list);
void	ft_unset(t_main_list *m_list);
int	env_check(t_main_list *m_list);


void print_list(t_mini *sadi);
//export and unset
void	ft_unset(t_main_list *m_list);
int	env_check(t_main_list *m_list);

//functions for append
void	append_fd(t_main_list *m_list);
void append_dup2(t_main_list *m_list, int j, int l);
void  calloc_append_norm(t_main_list **m_list);

//functions for infile
void    calloc_infile_norm(t_main_list **m_list);
void	infile_fd(t_main_list *m_list, int i, int l, int j);

//functions for outfile
void	outfile_fd(t_main_list *m_list, int l, int i, int j);
void    calloc_outfile_norm(t_main_list **m_list);
void outfile_dup2(t_main_list *m_list, int j, int l);

//functions for heredoc
void	find_fd_eof(t_main_list **m_list);
void	fill_heredoc(t_main_list **m_list);
void	eof_fd(t_main_list *m_list);

//functions for parser
t_main_list	*parser(t_mini *list);
void		all_args(t_main_list *m_list);
void		ft_initialize(t_main_list *temp);
t_main_list	*build_main_list(t_main_list *m_list,t_mini *list);
void		pipe_cmd(t_main_list *m_list, t_mini *list);
void		is_there_flag(t_main_list *m_list);
void		print_error();
void multi_close(t_main_list *m_list);

//functions for signals
void	signal_replace_line(int num);
void signal_quit(int signum);

//utils
int				isEven(int n);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_split(char const *s, char c);
unsigned int	str_in_array(const char *s, char delimiter);
int				ft_strnstr(const char *haystack, const char *needle, size_t len);
int				check_dquote(char *str);
int				ft_findlen(const char *s, char c);
int 			ft_str_in_str(const char *s1, int start, const char *s2);
int				ft_two_dim_len(char **str);
char			*ft_strtrim2(char const *s1, char set);
int				ft_size_array(char **array);
int				fix_cmp(const char *s1,const char *s2);
int 			ft_compare_c(char *str, t_main_list *m_list);
int				twod_len(char **str);
t_mini			*build_list(char **string, t_mini *list);

//free_them_all
void	free_t_expander(t_expander *expr);
void	free_t_main1(t_main_list *lst);
void	free_t_main2(t_main_list *lst);
void	free_t_main(t_main_list *lst);
void	three_d_free(char ***str);
void	two_d_free(char **str);
void	multi_free(t_main_list *m_l, t_mini *list, t_expander *exp, t_data *can);
void	ft_free_list(t_main_list *list);
void	free_stack(t_mini *stack);

//normal functions
t_mini	*lexer(t_data *can);
int	token_count(t_main_list *m_list, char *delimeter);
void	convert_space2(t_main_list **m_list);
void	print_nodes(t_main_list	*node_list);

#endif
