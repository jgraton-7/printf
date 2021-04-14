/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:36:53 by jgraton-          #+#    #+#             */
/*   Updated: 2021/04/14 00:05:20 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "lb/libft.h"

typedef struct	s_teste
{
	char type;
}				t_teste;



void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmem, size_t size);
char		*ft_itoa(int n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char *ft_int_to_hex(int arg);
char *ft_uppercase(char *str);
