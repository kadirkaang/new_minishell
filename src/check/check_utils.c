#include "../../includes/minishell.h"
#include <stdio.h>

int	quote_check(char *data)
{
	int	x;

	x = 0;
	x = quote_len1(data);
	if (x % 2 != 0)
	{
		printf("minishell: quote error\n");
		return (0);
	}
	return (1);
}

int	quote_len1(char *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (data[i])
	{
		if (data[i] == '\"' || data[i] == '\'')
			j++;
		i++;
	}
	return (j);
}

int	print_error(void)
{
	printf("%s\n", "minishell: syntax error near unexpected token");
	return (0);
}
