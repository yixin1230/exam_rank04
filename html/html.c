
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
			if (strncmp(&start[1], &all[i + 2], len - 1) == 0)
				return(i+len);
		}
		i++;
	}
	return (-1);
}

int	check_html(char *str)
{
	int i;
	char	*str_start;
	char	*str_end;
	int		end;
	int		start;
	int		lang;

	i = 0;
	start = 0;
	end = strlen(str);
	lang = 0;
	while(str[i])
	{	
		
		if (str[i] == '<' && str[i + 1] && str[i + 1] != '/')
		{
			int len = ft_strlen(&str[i + 1]) + 2;
			str_start = onestr(&str[i],len);
			printf("start:%s\n",str_start);
			i = len + i;
			printf("i:%i\n",i);
			end = find_end(str_start, &str[i], len, end);
			if (i + end > lang)
				lang = i + end;
			printf("lang:%i,lenstr:%li\n",lang, strlen(str));
			printf("end:%i\n",end);
			if (end == -1)
				return (-1);
			else if (end == i)
			{
				printf("end:%s\n",&str[end+1]);
				i = lang + 1;
				end = strlen(str);
			}
		}
		else
			i++;
	}
	if (lang + 1 < strlen(str))
	{
		return(-1);
	}
	return (0);
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
	return (0);
}