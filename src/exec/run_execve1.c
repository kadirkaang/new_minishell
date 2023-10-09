/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_execve1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:46 by kgoc              #+#    #+#             */
/*   Updated: 2023/10/09 17:03:52 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

char	**get_args(t_parse *data, t_list *tmp)
{
	char	**exec;
	int		i;
	int		j;

	j = 0;
	(void)tmp;
	if (data->text)
		while (data->text[j])
			j++;
	exec = malloc(sizeof(char *) * (j + 2));
	if (!exec)
		return (NULL);
	i = 0;
	exec[0] = ft_strdup(data->cmd);
	j = 1;
	if (data->text)
	{
		while (data->text[i])
		{
			exec[j] = ft_strdup(data->text[i++]);
			j++;
		}
	}
	exec[j] = NULL;
	return (exec);
}
