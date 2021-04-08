/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:12:22 by jgraton-          #+#    #+#             */
/*   Updated: 2021/04/07 23:12:57 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "lb/libft.h"

char ft_type(char *parameters, int count)
{
    if(parameters[count] == '%' && parameters[count + 1] == 'c')
        return 'c';
    if(parameters[count] == '%' && parameters[count + 1] == 'd')
        return 'd';
    if(parameters[count] == '%' && parameters[count + 1] == 's')
        return 's';
    if(parameters[count] == '%' && parameters[count + 1] == 'x')
        return 'x';
    return (0);
}


void ft_return_var(char *parameters, int count, va_list apt)
{
    int arg;
    int c;
    char *result;
    
    c = 0;
    arg = va_arg(apt, int);
    if(ft_type(parameters, count) == 'd')
    {
        result = ft_itoa(arg);
        while(result[c] != '\0')
        {
            write(1, &result[c], 1);
            c++;
        }
        
        write(1, "\n", 1);
    }
}

int ft_printf(const char *parameters, ...)
{   

    va_list apt;
    int c_pcem;

    c_pcem = 0;
    va_start(apt, parameters);
        while(parameters[c_pcem] != '\0')
        {
            if(parameters[c_pcem] == '%' && parameters[c_pcem + 1] == ft_type((char *)parameters, c_pcem))
            {
                ft_return_var((char *)parameters, c_pcem, apt);
            }
            //else
                //printf("sem /100\n");  
            c_pcem++;
        }
    return 1;           
}

int main(void)
{
    char *str;
    int c = 'c';
    int x = 10;
    char teste = 'c';

    ft_printf("%d %d %c ", x , c, teste);
}
