/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uppercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:22:37 by jgraton-          #+#    #+#             */
/*   Updated: 2021/04/13 14:29:19 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_uppercase(char *str)
{
	int count;

	count = 0;
	while(str[count] != '\0')
	{
		if (str[count] >= 97 && str[count] <= 122 )
			str[count] = (str[count] - 32);
		count++;
	}
	return (str);
}
