#include "minishell.h"

void    which_echo_command(char *array, int flag)
{
    //double quotes part
    int i;
    if(flag == 1)
        i=5;
    else
        i=7;
    while(array[i])
    {
        if(array[i] == '"')
        {
            while(array[i] && array[i] != '"')
                printf("%c", array[i++]);
        }
        else
        {
            while(array[i] && array[i] != '"')
                printf("%c", array[i++]);
        }
        i++;
    }
    if(flag == 1)
        printf("\n");
}