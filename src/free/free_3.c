#include "../../includes/minishell.h"
#include <stdlib.h>

void	error_free(t_list **node)
{
	if (!*node)
		return ;
	if ((*node)->next != NULL)
		free_node((*node)->next);
	if ((*node)->content)
		(*node)->content = (free((*node)->content), NULL);
	if ((*node))
		(*node) = (free(*node), NULL);
}

void	total_free()
{
	free_loop(0);  //sadece cmd yi freelemek için
	free_(); // enviroment ve history yi freelemek için
	free(g_shell->lex_list);
	free(g_shell);
	exit(1);
}
