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
