
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//send str form second char return the lenth 'afsd>', if not close return -1
int closed_html(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '<')
			return -1;
		else if (str[i] == '>')
		{
			if (i == 0)
				return -1;
			else 
				return i;
		}
		i++;
	}
	return -1;
}

int closed_br(char *str)
{
	int i = 0;
	int end = 0;
	int start = 0;
	while (str[i])
	{
		if (str[i] == '<')
			end++;
		if (str[i] == '>')
			start++;
		i++;
	}
	if (end == start)
		return 1;
	return -1;
}

int	check_html(char *str)
{
	char tags[200][200];
	int i = 0;
	int j = -1;
	int nb_end = 0;
	int nb_start = 0;
	if (!str)
		return -1;
	if (closed_br(str)< 0)
		return -3;
	while (str[i])
	{
		if (str[i] == '<')
		{
			if (str[i+1] == '/')//check if ending tag
			{
				i += 2;
				nb_start++;
				int endlen = closed_html(&str[i]);
				if (endlen == -1)
					return -2;
				//printf("j:%i, %s vs %s\n",j, tags[j], &str[i]);
				if (!strncmp(tags[j],&str[i],endlen))
				{
					j--;
					//printf("j:%i, endlen: %i, tags[j]:%s\n",j, endlen,tags[j]);
				}
				if (j < -1)
					return(-3);
				i=i+endlen;
				//printf("end:i:%i\n",i);
			}
			else //check if starting tag
			{
				i++;
				if (!strncmp("img",&str[i], 3))
				{
					int imglen = closed_html(&str[i]);
					if (imglen == -1)
						return -2;
					i=i+imglen+1;
				}
				else
				{
					j++;
					nb_end++;
					int startlen = closed_html(&str[i]);
					if (startlen == -1)
						return -2;
					strncpy(tags[j],&str[i],startlen);
					//printf("startlen: %i, tags[j]:%s\n",startlen ,tags[j]);
					i=i+startlen+1;
					//printf("satrt: i:%i\n",i);
				}
			}
		}
		else
			i++;
	}
	if (nb_end != nb_start)
		return -5;
	return (j);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "KO\n", 3);
		return (1);
	}
	int i = check_html(argv[1]);
	//printf("check_html :%i\n",i);
	if (i == -1)
	{
		write(1, "OK\n", 3);
		return (0);
	}
	write(1, "KO\n", 3);
	return (1);
}