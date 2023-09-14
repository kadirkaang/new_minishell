#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
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

//free
void	free_(void);
void	free_loop(int control);

//lexer
void	lexer(void);
void	lex_list(char *cmd, t_lexer **lex_table);
char	*cmd_build(char *cmd);
void	cmd_build_(char *cmd, int *len, int *i);
int		cmd_build_other(int *i, int *len, char *cmd);
char	*set_build(char *str);
void	set_other(char *data, char *str, int *j, int i);
void	set_other_other(char *data, char *str, int *j, int i);
int		quote_len(char *data);

//expander
void	expander(void);
void	get_env_to_lexlist(t_lexer **lex_list);
void	_get_env_to_lexlist(char **tmp, int i, t_list **data);
int		check_env(t_list *data, char *tmp, int i);
void	ft_tilde(char *tmp, char *str, t_list *data);

//expander_utils
void	does_dollar_make_sense(char *tmp, t_list *data,
	t_list *shell_data, int i);
char	*after_dark2(char *key, char *tmp);
void	_does_dollar_make_sense(t_env *y, char *before,
	char *after, t_list *data);
void	erase_after(char *tmp, t_list *data, int i);
void	_erase_after(t_list *data, char *str, char *tmp, int i);

//expander_utils2
void	get_after_num(char *tmp, t_list *data, int i);
char	*before_dollar(char *tmp);
void	ft_tilde_build1(t_list *data, char *key, char *tmp);
void	ft_tilde_build2(t_list *data, char *str);
void	free_tmp_tmp2(char *tmp, char *tmp2);

//expander_utils3
void	ft_exit_status(char *tmp, t_list *data);
char	*ft_after_dark(char *str);
char	*ft_before_dollar_control(char *tmp);
char	*quote_control(char *tmp);
void	quote_build(char **tmp, char **data, int *i, int *j);

//expander_utils4
void	free_str1(char *str1, int flag);
void	free_tmps(char *str, char *str2, char *str_tmp);
void	_ft_exit_status(t_list *data, char *str1);
int		ft_ultimatestrcmp(char *key, char *tmp, int i);

#endif