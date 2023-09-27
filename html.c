
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '>')
			return (i);
		else if (str[i] == '<')
			return (-1);
		i++;
	}
	return (i);
}

char *onestr(char *str, int len)
{
	int i;
	char *new;

	i = 0;
	new = malloc(len + 1);
	while(i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return(new);
}

int find_end(char *start, char *all, int len, int end)
{
	int i = 0;
	while (all[i])
	{
		if (all[i] == '<' && all[i + 1] && all[i + 1] == '/')
		{
			if (strncmp(start, &all[i+1], strlen(start) - 1))
				return(i);
		}
		i++;
	}
	return (-1);
}

int	check_html(char *str)
{
	int i;
	char	*start;
	int		end;

	i = 0;
	end = strlen(str);
	while(str[i])
	{	
		if (str[i] == '<' && str[i + 1] && str[i + 1] != '/')
		{
			int len = ft_strlen(&str[i + 1]) + 1;
			start = onestr(&str[i],len);
			i += len;
			end = find_end(start, &str[i], len, end);
			if (end = -1)
				return (-1);
			//find where to start and end next time;
		}
		else
			i++;
	}
	return (0)
}

int main(int argc, char **argv)
{
	if (argc <= 1 || check_html(argv[1]) < 0)
	{
		write(1, "KO\n", 3);
		return (1);
	}
	else
		write(1, "OK\n", 3);
	return (0)
}