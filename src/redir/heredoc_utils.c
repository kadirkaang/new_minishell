/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:27 by kgoc              #+#    #+#             */
/*   Updated: 2023/10/09 17:03:32 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>
#include <unistd.h>

void	killer(int sig)
{
	(void)sig;
	free_();
	free_loop(1);
	free(g_shell->lex_list);
	free(g_shell);
	write(1, "\n", 1);
	exit(1);
}

void	set_heredoc(int sig)
{
	(void)sig;
	g_shell->does_have_heredoc = -10;
}
