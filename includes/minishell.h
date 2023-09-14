#ifndef MINISHELL_H
# define MINISHELL_H

# include "/home/aaybaz/new_minishell/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

// not :t_list libft den geliyor

// enviroment değişkenler için
typedef struct s_env
{
	char	*key;
	char	*value;
}				t_env;

typedef struct s_lexer
{
	t_list	*lex;
}				t_lexer;

typedef struct s_shell
{
	t_list	*env;
	t_lexer	*lex_list;
	t_list	*parse;
	char	*cmd;
	char	*heredoc;
	int		does_have_heredoc;
	int		exec_status;
}				t_shell;

extern t_shell	*g_shell;

void	init_shell(t_shell **shell);
void	get_env(char **env, t_shell **shell);
void	free_str(char **str);
void	signals_control(void);
void	signals(int sig);
void	get_readline(void);

#endif