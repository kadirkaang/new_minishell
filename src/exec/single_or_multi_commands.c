/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_or_multi_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:47 by kgoc              #+#    #+#             */
/*   Updated: 2023/10/09 17:03:52 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	single_or_multi_command(void)
{
	t_list	*tmp;
	t_parse	*data;

	tmp = g_shell->parse;
	data = g_shell->parse->content;
	while (tmp)
	{
		data = tmp->content;
		if (data->type == 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
