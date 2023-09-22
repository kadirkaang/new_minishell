#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

t_shell	*g_shell;

void	get_readline(void)
{
	g_shell->cmd = readline("minishell-$ ");
	if (!g_shell->cmd)
		total_free();
	add_history(g_shell->cmd);
}

int	main(int ac, char **av, char **env)
{
	int		control;

	(void)av;
	control = 0;
	if (ac != 1)
		exit(printf("This program cannot accept any arguments\n"));
	init_shell(&g_shell);
	get_env(env, &g_shell);
	signals_control();
	while (1)
	{
		get_readline();
 		if (quote_check(g_shell->cmd))
		{
			lexer();
			expander();
			control = check();
			if (control)
				go_parser(env);
			else
			error_free(&(g_shell->lex_list)->lex);
		}
		free_loop(control);
	}
}

/* 
Lexer, kullanıcı girdisini alır ve onu daha küçük "token" parçalarına böler.
Expander, bu tokenların içeriğini daha fazla işlemek için kullanılır ve özel karakterleri (örneğin, değişkenler veya wildcards) değerlerle değiştirir.
Parser, genişletilmiş girdiyi bir komut ağacına çevirir, bu ağaç komutların mantıksal yapısını temsil eder.
Bu üç süreç, kullanıcı girdisinin işlenmesi için birbirini tamamlayan adımlardır.
Lexer, girdiyi düzenler ve daha anlamlı bir forma dönüştürür.
Expander, lexer'ın çıkardığı tokenları daha fazla işleyerek genişletir.
Parser, genişletilmiş girdiyi komutları temsil eden bir ağaca dönüştürür.
Bu sıralı işlemler, kullanıcı girdisinin daha iyi anlaşılabilir ve yorumlanabilir bir yapıya dönüştürülmesini sağlar.
*/