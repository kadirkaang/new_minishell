/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:06 by kgoc              #+#    #+#             */
/*   Updated: 2023/10/09 17:03:39 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	get_env(char **env, t_shell **shell)
{
	t_env	*a;
	char	**str;

    // neden ilk başta freeliyoruz.
	free((*shell)->env);
	(*shell)->env = NULL;
	
    // satir satir key value prensibi ile splitleyip
    // shell->env e tanımlanır.
    while (*env) 
	{
		a = malloc(sizeof(t_env));
		str = ft_split(*env, '=');
		a->key = ft_strdup(str[0]);
		a->value = ft_strdup(str[1]);
		// printf("%s", a->key);
		// printf("=%s\n", a->value);
		ft_lstadd_back(&(*shell)->env, ft_lstnew(a));
		free_str(str);
		env++; // bir sonraki satıra geçirir.
	}
}
