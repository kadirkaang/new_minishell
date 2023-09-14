#include "../../includes/minishell.h"

void	signals(int sig)
{
	if (sig == 2)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signals_control(void)
{
	signal(SIGINT, signals);
	signal(SIGQUIT, SIG_IGN);
}
