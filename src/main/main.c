#include "../../includes/minishell.h"

t_shell	*g_shell;

int	print_cmd(char *cmd)
{	
	int i = 0;
	while (cmd[i])
	{	
		printf("%c",cmd[i]);
		i++;
	}
	printf("/n");
	return (0);
}

void	get_readline(void)
{
	g_shell->cmd = readline("minishell-$ ");
/* 	if (!g_shell->cmd)
	{
		free_loop(0);
		free_();
		free(g_shell->lex_list);
		free(g_shell);
		exit(1);
	} */
	add_history(g_shell->cmd);
	print_cmd(g_shell->cmd);
}

int	main(int ac, char **av, char **env)
{
	//int		control;

	(void)av;
	//control = 0;
	if (ac != 1)
		exit(printf("This program cannot accept any arguments\n"));
	init_shell(&g_shell);
	get_env(env, &g_shell);
	signals_control();
	while (1)
	{
		get_readline();
/* 		if (quote_check(g_shell->cmd))
		{
			lexer();
			expander();
			control = check();
			if (control)
				go_parser(env);
			else
				error_free(&(g_shell->lex_list)->lex);
		} */
		//free_loop(control);
	}
}
