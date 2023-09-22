#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
#include <stdio.h>


# define EXEC 0
# define HEREDOC 1
# define PIPE 2
# define GREAT 3
# define GREATER 4
# define LESS 5
# define STDINN 0
# define STDOUT 1
# define STDERR 2

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

typedef struct s_parse
{
	char	*cmd;
	char	**text;
	int		type;
	int		outfile;
	int		infile;
	int		fd;
	int		pid;
	int		control;
}				t_parse;

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
void	free_env(void);
void	free_str(char **str);
void	signals_control(void);
void	signals(int sig);
void	get_readline(void);

//free
void	free_(void);
void	free_loop(int control);
void	total_free();
void	error_free(t_list **node);

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

// check
int		check(void);
int		quote_check(char *data);
int		quote_len1(char *data);
int		cmd_is_valid(t_lexer *lex_list);
int		is_valid_other(char *a, char *b);
int		print_error(void);

//parser
void	go_parser(char **env);
int		ft_parser(void);
void	parse_priority_order(t_lexer *lexer);
void	free_node(t_list *node);
void	free_tmp(t_list *tmp);
char	*get_hard(t_list *lex);
void	get_text(t_parse **parse, char *str, int j, int a);
void	get_text_utils(char **tmp, t_parse ***parse, int j, int k);
void	tokenize_type(t_parse **parse, const char *str);
void	parse_init(void);
t_parse	*parse_(int *j, t_list *new, int *i);
void	free_parse(t_parse *parse);
void	welcome_to_parse(t_list	*node, int i, int j, int flag);
void	parse_else_if(t_parse **parse, t_list *new, char *str, int *j);
void	parse_if(t_list *new, t_parse **parse);
void	free_text(char **text);

//create_files
int		create_files(void);
void	create_out_files(t_parse *data3, t_list *tmp3);
char	*ft_strjoin2(char *s1, const char *s2);
void	other_text_create(t_list *tmp3, t_list *tmp);
void	other_out_files(t_list *tmp3, t_list *tmp);
int		create_in_files(t_parse *data3, t_list *tmp3);
int		create_in_files_other(t_parse *data, char *pwd);


//exec 
void	free_parser(void);
void	execute_builtin_command(t_list *tmp, int *fd, int fd_index);
int		is_builtin(t_list *tmp);
void	exec_others(t_list *data, char **env, int *fd, int fd_index);
int		single_or_multi_command(void);
char	**get_args(t_parse *data, t_list *tmp);
void	execve_child_free(char **str);
void	exec_others(t_list *data, char **env, int *fd, int fd_index);
void	run_execve(t_list *data1, char **env, int *fd, int fd_index);
void	search_path(t_parse *data, int i);
char	*_search_path(void);
char	*search_command(char *cmd, char **value);
void	run_command(char **env, t_list *tmp, int *fd, int fd_index);
void	run_single_command(char **env, t_list *data);
void	_multi_command(t_parse **data, t_list **tmp);
void	exec(char **env);


//pipe
void	wait_all(void);
void	switch_pipe(int **fd);
void	clear_pipe(int *fd);
void	create_dup(t_list *data1, int *fd, int fd_index);
void	_create_dup(void);
int		*create_pipe(void);



void	loop_heredoc(void);
void	set_heredoc(int sig);
void	killer(int sig);

//builtin
void	exec_echo(t_parse *data);
void	exec_export(t_parse *data);
void	exec_cd1(char *str, t_parse *data);
void	exec_unset(t_parse *data);
void	exec_env(void);
void	exec_pwd(t_parse *data);
void	exec_cd(t_parse *data);
char	*get_home(void);

#endif