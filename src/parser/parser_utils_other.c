#include "../../includes/minishell.h"
#include <stdlib.h>

void	go_parser(char **env)
{
	(void)env;
	if (ft_strcmp(g_shell->cmd, ""))
	{
		if (ft_parser())
			exec(env);
	}
}

void	free_parse(t_parse *parse)
{
	if (!parse)
		return ;
	free(parse->cmd);
	free_text(parse->text);
	free(parse);
}
