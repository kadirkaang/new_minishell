#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

void remove_character(char *str, char c) {
    int len = ft_strlen(str);
    int i;
	int j;

	j = 0;
	i = -1;
	while (i++ < len)
	{
		if (str[i] != c)
			str[j++] = str[i];
	}
    str[j] = '\0';
}

void	remove_at_index(char *data, int index)
{
	int	len;

	len = ft_strlen(data);
	while (index < len - 1)
	{
		data[index] = data[index + 1];
		index++;
	}
	data[index] = '\0';

}

void	quote_control1(char *data)
{
	int		pos[2];
	int		i;
	char	c;

	i = 0;
	pos[0] = 0;
	pos[1] = 0;
	while (data[i] != '\0')
	{
		if (data[i] == '\'' || data[i] == '\"')
		{
			c = data[i];
			if (pos[0] == 0)
			{
				pos[0] = i;
				i++;
				while (data[i] != '\0')
				{
					if (data[i] == c)
					{
						pos[1] = i;
						i++;
						break;
					}
					i++;
				}
				if (pos[1] == 0)
				{
					remove_at_index(data, pos[0]);
					quote_control1(data);
				}
				else
					quote_control1(&data[i]);
			}
		}
		i++;
	}
}

char	*quote_check(char *data)
{	
	remove_character(data, 92);
	remove_character(data, 59);
	quote_control1(data);
	return (data);
}

int	print_error(void)
{
	printf("%s\n", "minishell: syntax error near unexpected token");
	return (0);
}
