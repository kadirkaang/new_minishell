/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:21 by kgoc              #+#    #+#             */
/*   Updated: 2023/10/09 17:03:35 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

void	go_parser(char **env)
{
	(void)env;
	if (ft_strcmp(g_shell->cmd, ""))
	{
		if (ft_parser())
			exec(env);
	}
}

void	free_parse(t_parse *parse)
{
	if (!parse)
		return ;
	free(parse->cmd);
	free_text(parse->text);
	free(parse);
}
