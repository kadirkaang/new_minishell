/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:57 by kgoc              #+#    #+#             */
/*   Updated: 2023/10/09 17:03:48 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

void	_free_env(t_list *tmp2)
{
	t_env	*tmp;

	while (tmp2)
	{
		tmp = tmp2->content;
		if (tmp2->content)
		{
			if (tmp->key)
				free(tmp->key);
			if (tmp->value)
				free(tmp->value);
			free(tmp);
		}
		tmp2 = tmp2->next;
	}
	while (g_shell->env)
	{
		tmp2 = g_shell->env;
		g_shell->env = g_shell->env->next;
		if (tmp2)
			free(tmp2);
	}
}

void	free_env(void)
{
	t_list	*tmp2;

	tmp2 = g_shell->env;
	if (tmp2 && tmp2->content)
		_free_env(tmp2);
	else if (g_shell->env && !g_shell->env->content)
		free(g_shell->env);
} 

void	free_(void)
{
	free_env();
	rl_clear_history();
}

void	free_loop(int control)
{   
    (void)control;
	if (g_shell->cmd)
		free(g_shell->cmd);

	if (control)
	{
		if (g_shell->parse)
			free_parser();
	} 
	if (g_shell->heredoc)
	{
		free(g_shell->heredoc);
		g_shell->heredoc = NULL;
	} 

}

void	execve_child_free(char **str)
{
	free_();
	free_loop(1);
	free_text(str);
	free(g_shell->lex_list);
	free(g_shell);
}
