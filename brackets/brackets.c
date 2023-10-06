/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brackets.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 17:09:07 by yizhang       #+#    #+#                 */
/*   Updated: 2023/10/04 17:09:07 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_match(char open, char close)
{
    if ((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}'))
        return 1;
    return 0;
}

char *check_str(char *str)
{
    while(*str)
    {
        if (*str == '}' || *str == ')' || *str == ']')//if close return the last char
            return(str);
        else if (*str == '{' || *str == '(' || *str == '[')//if open, try to find the end and go to the end adress.
        {
            if (check_match(*str, *check_str(str + 1)))
                str = check_str(str + 1);
            else
                return "2";
        }
        str++;
    }
    return "1";
}

int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;
    int i = 1;
    while (argv[i])
    {
        if (*check_str(argv[i]) != '1')
        {
            write(1,"Error\n",6);
            return 1;
        }
        i++;
    }
    write(1,"OK\n", 3);
    return 0;
}