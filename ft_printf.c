/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:12:22 by jgraton-          #+#    #+#             */
/*   Updated: 2021/04/14 14:58:37 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "lb/libft.h"
#include "ft_printf.h"

char ft_type(char *parameters, int count, int n)
{
	if (parameters[count + n] == 'c')
		return ('c');
	if ((parameters[count + n] == 'd'
	|| parameters[count + n] == 'i'))
		return ('d');
	if (parameters[count + n] == 's')
		return ('s');
	if (parameters[count + n] == 'x')
		return ('x');
	if (parameters[count + n] == 'X')
		return ('X');
	if (parameters[count + n] == 'p')
		return ('p');
	if (parameters[count + n] == '-')
		ft_type(parameters, count, 2);
	return (0);
}

void ft_return_var(char *parameters, int count, va_list apt)
{
	int arg;
	int c;
	char *result;
	char p_c;
	char *ch;
	int c2;
	char **p;
	t_teste teste;
	teste.type = 'c';

	c = 0;
	c2 = 0;
	if (ft_type(parameters, count, 1) == 'd')
	{
		arg = va_arg(apt, int);
		result = ft_itoa(arg);
		while (result[c] != '\0')
			write(1, &result[c++], 1);
	}
	else if (ft_type(parameters, count, 1) == 'c')
	{
		arg = va_arg(apt, int);
		p_c = arg;
		write(1, &p_c ,1);
	}
	else if (ft_type(parameters, count, 1) == 's')
	{
		ch = va_arg(apt, char *);
		while (ch[c2] != '\0')
			write (1, &ch[c2++], 1);
	}
	else if (ft_type(parameters, count, 1) == 'x')
	{
		arg = va_arg(apt, int);
		result = ft_int_to_hex(arg);
		while (result[c2] != '\0')
			write (1, &result[c2++], 1);
	}
	else if (ft_type(parameters, count, 1) == 'X')
	{
		arg = va_arg(apt, int);
		result = ft_int_to_hex(arg);
		ft_uppercase(result);
		while (result[c2] != '\0')
			write (1, &result[c2++], 1);
	}
	else if(ft_type(parameters, count, 1) == 'p')
	{
		ch = va_arg(apt, char *);
		p = &ch;
		// laste
	}
	else if(ft_type(parameters, count, 1) == '-')
	{

	}
}

int ft_printf(const char *parameters, ...)
{

	va_list apt;
	int c_pcem;

	c_pcem = 0;
	va_start(apt, parameters);
		while (parameters[c_pcem] != '\0')
		{
			if (parameters[c_pcem] == '%'&&
			parameters[c_pcem + 1] == ft_type((char *)parameters, c_pcem, 1))
			{
				ft_return_var((char *)parameters, c_pcem, apt);
				c_pcem = c_pcem + 1;
			}
			else
				write (1, &parameters[c_pcem], 1);
			c_pcem++;
		}
	return (1);
}

int main(void)
{
	char *str;
	int c = 'e';
	int x =181516;
	char *teste = "string";

	ft_printf("teste %d função printf %c sem space %p \n", x , c, teste);
	printf("\nteste %d função printf %c sem space %p \n", x , c, teste);
}
