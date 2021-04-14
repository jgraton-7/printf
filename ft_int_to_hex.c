/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 02:09:30 by jgraton-          #+#    #+#             */
/*   Updated: 2021/04/13 23:47:06 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char ft_over_nine(int c2)
{
	if(c2 == 10)
		return ('a');
	else if(c2 == 11)
		return('b');
	else if(c2 == 12)
		return('c');
	else if(c2 == 13)
		return('d');
	else if(c2 == 14)
		return('e');
	else if(c2 == 15)
		return('f');
	return (0);
}

char *ft_swap(char *hex)
{
	char *tmp;
	int count;
	int c2;

	c2 = 0;
	count = ft_strlen(hex);
	tmp = ft_strdup(hex);
	free(hex);
	hex[count] = '\0';
	count -= 1;
	while (count >= 0)
	{
		hex[c2] = tmp[count];
		c2++;
		count--;
	}
	return (hex);
}

char *ft_int_to_hex(int arg)
{
	char *hex;
	int count;
	int c2;

	count = 0;
	if(!(hex = ft_calloc(count,sizeof(char *))))
		return (0);
	while(arg > 16)
	{
		c2 = arg % 16;
		if (c2 > 9 && c2 < 16)
			hex[count++] = ft_over_nine(c2);
		else if(c2 >= 0 && c2 < 10)
			hex[count++] = c2 + '0';
		arg /= 16;
	}
	if (arg > 9 && arg < 16)
	{
		hex[count] = ft_over_nine(arg);
	}
	else if(arg >= 0 && arg < 10)
	{
		hex[count] = arg + '0';
	}
	hex = ft_swap(hex);
	return (hex);
}

// int main()
// {
// 	char *str;

// 	str = ft_int_to_hex(15424542);
// 	printf("\n%x\n", 15424542);
// 	printf("%s", str);
// }
