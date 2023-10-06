
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char *check_close(char *str)
{
	int i = 1;
	while (str[i])
	{
		if (str[i] == '<')
			return "2";
		else if (str[i] == '>')
			return (&str[i]);
		i++;
	}
	return "1";
}

char ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '>')
			return i;
		i++;
	}
	return i;
}
int check_match(char *open, char *close)
{
	int i = 0;
	printf("open: %s,close :%s\n",open, close);
	if ((check_close(open) != "2" && check_close(open) != "1" ) && check_close(close) != "1")
	{
		int len = ft_strlen(open);
		printf("len:%i\n",len);
		printf("close :%s\n",close - len+ 1);
		if (strncmp(&open[1], close - len, len) == 0)
			return 1;
	}
	return 0;
}

char	*check_html(char *str)
{
	while (*str)
	{
		if (*str == '<' && *(str + 1) == '/')
		{
			if (check_close(str) != "2" || check_close(str) != "1")
				return (check_close(str));
		}
		else if (*str == '<' && *(str + 1) != '/')
		{
			if (strncmp(str, "<img", 4)==0 && (check_close(str) != "2" || check_close(str) != "1"))
				str = check_close(str);
			else if (check_match(str, check_html(str + 1)))
				str = check_html(str + 1);
			else
				return "2";	
		}
		str++;
	}
	return "1";
}

int main(int argc, char **argv)
{
	if (argc != 2 || check_html(argv[1]) != "1")
	{
		write(1, "KO\n", 3);
		return (1);
	}
	else
		write(1, "OK\n", 3);
	return (0);
}