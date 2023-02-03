/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:53:20 by emyilmaz          #+#    #+#             */
/*   Updated: 2023/01/31 00:42:00 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_go_somewhere(t_main_list *m_list, char *t0, char *t1, char *t2)
{
	struct stat	file_stat;

	t2 = get_env_after_equal(g_list->environment[env_check("PWD")]);
	t0 = ft_strjoin(t2, "/");
	t1 = ft_strjoin(t0, m_list->args[1]);
	if ((access(t1, F_OK) == 0) && (stat(t1, &file_stat) != -1))
	{
		if (S_ISDIR(file_stat.st_mode))
			cd_go_somewhere_2(t1);
		else
		{
			printf("bash: cd: %s: Not a directory\n", m_list->args[1]);
			g_list->exit_status = 1;
		}
	}
	else
	{
		printf("bash: cd: %s: No such file or directory\n", m_list->args[1]);
		g_list->exit_status = 1;
	}
	free(t0);
	free(t1);
	free(t2);
}

void	cd_go_somewhere_2(char *temp1)
{
	char	*temp3;
	char	*temp;
	char	*tem2;

	int (del) = 0;
	temp3 = get_env_after_equal(g_list->environment[env_check("PWD")]);
	del = env_check("OLDPWD");
	temp = ft_strjoin("OLDPWD=", temp3);
	free(g_list->environment[del]);
	g_list->environment[del] = ft_strdup(temp);
	free(temp3);
	del = env_check("PWD");
	free(g_list->environment[del]);
	tem2 = ft_strjoin("PWD=", temp1);
	g_list->environment[del] = ft_strdup(tem2);
	temp3 = get_env_after_equal(g_list->environment[env_check("PWD")]);
	chdir(temp3);
	g_list->exit_status = 0;
	free(temp);
	free(tem2);
	free(temp3);
}

void	cd_just_dot_dot(void)
{
	char	*oldpwd2;
	char	*temp;
	char	*newpwd;

	int (bi) = 0;
	int (ti) = 0;
	oldpwd2 = get_env_after_equal(g_list->environment[env_check("PWD")]);
	temp = ft_strjoin("OLDPWD=", oldpwd2);
	bi = env_check("OLDPWD");
	free(g_list->environment[bi]);
	g_list->environment[bi] = ft_strdup(temp);
	newpwd = get_env_previous_slash(g_list->environment[env_check("PWD")]);
	ti = env_check("PWD");
	free(g_list->environment[ti]);
	g_list->environment[ti] = ft_strdup(newpwd);
	free(oldpwd2);
	free(newpwd);
	free(temp);
	chdir("..");
}

void	cd_go_home(void)
{
	char	*oldpwd;
	char	*new_pwd;
	char	*temp;

	int (bi) = 0;
	int (ti) = 0;
	oldpwd = get_env_after_equal(g_list->environment[env_check("PWD")]);
	new_pwd = ft_strjoin("OLDPWD=", oldpwd);
	bi = env_check("OLDPWD");
	free(g_list->environment[bi]);
	g_list->environment[bi] = ft_strdup(new_pwd);
	free(oldpwd);
	free(new_pwd);
	oldpwd = get_env_after_equal(g_list->environment[env_check("HOME")]);
	new_pwd = ft_strjoin("PWD=", oldpwd);
	ti = env_check("PWD");
	free(g_list->environment[ti]);
	g_list->environment[ti] = ft_strdup(new_pwd);
	free(oldpwd);
	free(new_pwd);
	temp = get_env_after_equal(g_list->environment[env_check("HOME")]);
	chdir(temp);
	free(temp);
}

void	ft_cd(t_main_list *m_list)
{
	char *(temp0) = NULL;
	char *(temp1) = NULL;
	char *(temp2) = NULL;
	if (!ft_strcmp(m_list->args[0], "cd") && !m_list->args[1])
		cd_go_home();
	else if (!ft_strcmp(m_list->args[0], "cd") && m_list->args[1][0] == '~')
		cd_go_home();
	else if (!ft_strcmp(m_list->args[0], "cd") && m_list->args[1])
	{
		if (!ft_strcmp(m_list->args[1], ".."))
			cd_just_dot_dot();
		else if (fix_cmp(m_list->args[1], "."))
			cd_go_somewhere(m_list, temp0, temp1, temp2);
	}
}
