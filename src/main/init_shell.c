#include "../../includes/minishell.h"
#include <stdlib.h>

void	init_shell(t_shell **shell)
{
	*shell = malloc(sizeof(t_shell));
	(*shell)->env = malloc(sizeof(t_env));
	(*shell)->lex_list = malloc(sizeof(t_lexer));
	(*shell)->lex_list->lex = NULL;
	(*shell)->does_have_heredoc = 0;
	(*shell)->exec_status = 0;
	(*shell)->heredoc = NULL;
	(*shell)->cmd = NULL;
}