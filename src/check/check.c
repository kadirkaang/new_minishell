/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:02:32 by kgoc              #+#    #+#             */
/*   Updated: 2023/10/09 17:03:55 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_valid_other(char *a, char *b)
{
	if ((a[0] == '<' && !a[1]) && !b)
		return (0);
	else if ((a[0] == '>' && !a[1]) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && !a[1])) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && a[1] == '<')) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '>' && a[1] == '>')) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && a[1] != '<'))
		&& (b[0] == '<' || b[0] == '>' || b[0] == '|'))
		return (0);
	else if ((a[0] == '>' && a[1] != '>')
		&& (b[0] == '<' || b[0] == '>' || b[0] == '|'))
		return (0);
	else if (((a[0] == '<' && a[1] == '<'))
		&& (b[0] == '>' || b[0] == '<' || b[0] == '|'))
		return (0);
	else if ((a[0] == '>' && a[1] == '>')
		&& (b[0] == '<' || b[0] == '>' || b[0] == '|'))
		return (0);
	else if ((a[0] == '|' && !a[1] && b[0] == '|' && !b[1]))
		return (0);
	return (1);
}

// lexer = echo , << , ali
int	cmd_is_valid(t_lexer *lex_list)
{
	t_list	*tmp;
	char	*a;
	char	*b;
	int		i;

	i = 0;
	b = NULL; // b listede contentden sonra gelen next elemanı check etmek için
	a = NULL; // a contentin içeriğini check etmek için
	tmp = lex_list->lex;
	while (tmp)
	{
		a = tmp->content;  // a = ali ile bitti
		if (tmp->next)
			b = tmp->next->content; // b = ali ile bitti ##		// | (tek başına başta kullanılırsa)
		if ((a[0] == '|' && !a[1]) && i == 0)
			return (print_error());
		else if ((a[0] == '>' && !a[1]) && !b) //  > (tek başına kullanılırsa)  // => is valid other a alınabilir . 
			return (print_error());
		else // redirectionları check etmek için 
			if (!is_valid_other(a, b))
				return (print_error());
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	check(void)
{
	return (cmd_is_valid(g_shell->lex_list));
}
