/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:14:32 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/13 12:14:33 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

long long	ft_atoi(const char *a)
{
	int i;
	int zn;
	long long res;

	i = 0;
	zn = 1;
	res = 0;
	while (a[i])
	{
		if ((a[i] >= 9 && a[i] <= 13) || a[i] == ' ')
		{
			i++;
			continue;
		}
		if (a[i] == '-')
			zn = -1;
		if (a[i] == '+' || a[i] == '-')
			i++;
		while (a[i] >= '0' && a[i] <= '9')
			res = res * 10 + zn * (a[i++] - '0');
		return (res);
	}
	return (0);
}

char	*ft_strnew(size_t size)
{
	char	*q;
	size_t	i;

	q = (char*)malloc((int)size + 1);
	i = 0;
	if (q)
	{
		q[size] = '\0';
		while (i < size)
			q[i++] = 0;
		return (q);
	}
	else
		return (0);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *q;

	q = ft_strnew(len);
	if (!q || !s)
		return (0);
	q = strncpy(q, &(s[start]), len);
	return (q);
}

static int		ft_wordc(char const *s)
{
	int i;
	int in;
	int res;

	i = 0;
	res = 0;
	in = 0;
	while (s[i])
	{
		if (!in && s[i] > ' ')
			in = 1;
		else if (in && s[i] <= ' ')
		{
			in = 0;
			res++;
		}
		i++;
	}
	if (in)
		res++;
	return (res);
}

static char		*ft_getword(char const *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] > ' ')
		i++;
	return (ft_strsub(s, 0, i));
}

char			**ft_strsplit(char const *s, int *size)
{
	char	**res;
	int		i;
	int		j;
	int		in;

	if (!s)
		return (0);
	*size = ft_wordc(s);
	res = (char**)malloc(sizeof(char*) * (*size + 1));
	res[ft_wordc(s)] = 0;
	j = 0;
	i = 0;
	in = 0;
	while (s[i++])
	{
		if (!in && s[i - 1] > ' ')
		{
			in = 1;
			res[j++] = ft_getword(&(s[i - 1]));
		}
		else if (in && s[i - 1] <= ' ')
			in = 0;
	}
	return (res);
}
