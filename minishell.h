/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:13:43 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 06:25:31 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include "libft/source/libft.h"

typedef struct ss_list
{
	char			*data;
	struct ss_list	*next;
	struct ss_list	*prev;
}	t_mini;

typedef struct ss_data
{
	char	**str;
	char	*data;
	char	*name;
}	t_data;

typedef struct s_expander
{
	char	**env_head;
	char	**env_tail;
	char	*temp_head;
	char	*temp;
	char	*temp_tail;
	char	*src;
	char	**changed_env;
	char	*temporary;
}	t_expander;

typedef struct s_main_list
{
	char				*pipe_cmd;
	char				*path;
	int					*infile_fd_r;
	int					*infile_fd_l;
	char				**infile_name_l;
	char				**infile_name_r;
	int					*outfile_fd_r;
	int					*outfile_fd_l;
	char				**outfile_l;
	char				**outfile_r;
	char				*eof;
	int					eof_fd;
	int					*append_fd_r;
	int					*append_fd_l;
	char				**append_r;
	char				**append_l;
	char				**args;
	char				*cmd;
	char				*flag;
	char				**tdm;
	struct s_main_list	*next;
	int					std_out;
}	t_main_list;

typedef struct s_env
{
	t_mini		*g_env_list;
	char		**export;
	char		**environment;
	char		*name;
	int			exit_status;
	int			sayac;
	int			f;
	t_data		*can;
	t_expander	*exp;
}	t_env;

extern t_env	*g_list;

/* BUILTINS */
int			ft_echo(t_main_list *m_list);
void		ft_pwd(t_expander *exp);
void		ft_cd(t_main_list *m_list);
void		ft_exit(t_main_list *m_list);
void		ft_env(void);
int			any_pipe(t_mini *list);
int			is_builtin(t_main_list *m_list);
int			is_builtin2(t_main_list *m_list);
int			is_builtin3(t_main_list *m_list);

/* functions for lexer */
int			check_input(char *str);
int			counter(char *input);
int			counter2(char **input);
int			ft_check(char *str);
int			left_right(char *input, int *j, int flag);
int			ft_check_quotes(char *str);
int			ft_compare(char *str, int i);
char		**ft_array_copy_stuff(char *array, char **temp, int *y, int flag);
char		**ft_character_copy_stuff(char **temp, char *str, int *i, int *y);
char		**monster_truck(char *str, int i, int j, int y);
char		**this_is_not_split(char **string, int len, int j, int r);
char		**temproray_copy(char ***temp, char **daft, int r, int *j);
void		convert_space(char *str);
int			check_list(t_mini	*list);

/* functions for expander */
void		expander_trim_dquote(t_mini ***list_two, t_expander ***exp);
void		expander_trim_squote(t_mini **list_two, t_expander **expander);
void		check_greens(t_mini **lst2, t_expander **exp, int j);
void		expander_uptade(t_mini *lst2, t_expander *exp);
void		no_greens(t_mini ***lst2);
void		expander_trim_dquote_norm(t_expander ****exp, char **arr);
t_expander	*expander(t_mini *list);
void		ft_expand_dollar(t_expander ***exp, t_mini **lst2, int *j);
void		ft_parse_pipe_cmd(t_main_list **tmp, t_mini *list);

/* functions for cmd */
void		find_cmd(t_main_list *m_list);
void		fill_it_all(char **array, char ****all_path, t_main_list *m_list);
void		trying_find_cmd(t_main_list **m_list, char ***all_path);

void		ft_export(t_main_list *m_list);
void		ft_unset(t_main_list *m_list);

/* functions for unset */
void		ft_unset(t_main_list *m_list);
void		ft_unset_export(int line);
void		ft_unset_env(int line);
void		add_export_is_there(t_main_list *m_list, int line);

/* functions for change directory */
void		cd_go_somewhere(t_main_list *m_list, char *t0, char *t1, char *t2);
void		cd_go_home(void);
void		cd_go_somewhere_2(char *temp1);
void		cd_just_dot_dot(void);

/* functions for change directory utilities */
char		*get_env_after_equal(char *ptr);
char		*get_env_previous_slash(char *ptr);
char		*ft_after_last_slash(char *ptr);
int			export_check(char *ptr);

/* functions for append */
void		append_fd(t_main_list *m_list, int l, int i, int j);
void		append_dup2(t_main_list *m_list, int j, int l);
void		calloc_append_norm(t_main_list **m_list);

/* functions for infile */
void		calloc_infile_norm(t_main_list **m_list);
void		infile_fd(t_main_list *m_list, int i, int j);

/* functions for outfile */
void		outfile_fd(t_main_list *m_list, int l, int i, int j);
void		calloc_outfile_norm(t_main_list **m_list);
void		outfile_dup2(t_main_list *m_list, int j, int l);

/* functions for heredoc */
void		find_fd_eof(t_main_list **m_list);
void		fill_heredoc(t_main_list **m_list);
void		eof_fd(t_main_list *m_list);

/* functions for parser */
int			ft_compare_parser2(char *str, t_main_list *m_list);
int			ft_compare_parser(char *str, t_main_list *m_list);
void		all_args(t_main_list *m_list);
void		ft_initialize(t_main_list *temp);
void		pipe_cmd(t_main_list *m_list, t_mini *list);
void		is_there_flag(t_main_list *m_list);
void		print_error(void);
void		multi_close(t_main_list *m_list);

/* functions for executer */
void		executer(t_main_list *m_list, t_mini *list, t_expander *exp,
				int fd_tmp);
void		run_executer_zero(int *tmp_fd, t_main_list *m_list);
void		run_executer_one(int **fd, int *tmp_fd, t_main_list *m_list);
void		run_executer_two(int **fd, int *tmp_fd, t_main_list *m_list);
void		run_executer_three(int *fd_tmp, int *tmp_fd, t_main_list *m_list);
void		execute(int tmp_fd, t_main_list *m_list);
int			operator_cmp(t_main_list *m_list, int i);
int			ft_str_in_char(const char *s, int c);
void		executer2(t_main_list **m_l, t_mini **list, int *fd_tmp);

t_main_list	*parser(t_mini *list, t_main_list *m_list);
t_main_list	*build_main_list(t_main_list *m_list, t_mini *list);

/* functions for signals */
void		signal_replace_line(int num);
void		signal_quit(int signum);
void		ft_signal(void);

/* functions for exit utils */
int			is_numeric(char *argv);
int			is_all_numeric(char **argv);

/* utilities */
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strnstr2(const char *haystack, const char *needle, size_t len);
int			check_dquote(char *str);
int			ft_findlen(const char *s, char c);
int			ft_str_in_str(const char *s1, int start, const char *s2);
int			ft_size_array(char **array);
int			fix_cmp(const char *s1, const char *s2);
int			ft_compare_parser(char *str, t_main_list *m_list);
int			ft_size_array(char **str);
char		*ft_strtrim2(char const *s1, char set);
char		**ft_split(char const *s, char c);
t_mini		*build_list(char **string, t_mini *list);
int			ft_str_in_str2(const char *s, char *c);
int			ft_str_in_char(const char *s, int c);

/* free functions */
void		free_t_expander(t_expander *expr);
void		free_t_main1(t_main_list *lst);
void		free_t_main2(t_main_list *lst);
void		free_t_main(t_main_list *lst);
void		three_d_free(char ***str);
int			two_d_free(char **str);
void		multi_free(t_main_list *m_l, t_mini *list, t_expander *exp);
void		ft_free_list(t_main_list *list);
void		free_stack(t_mini *stack);
void		free_data(t_data *can);

/* normal functions */
t_mini		*lexer(t_data *can);
int			token_count(t_main_list *m_list, char *delimeter);
void		convert_space2(t_main_list **m_list);
void		print_nodes(t_main_list	*node_list);
int			env_check(char *ptr);

#endif
