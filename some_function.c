/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:43:28 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/09 14:46:49 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_numbcounter(unsigned int n)
{
	int				i;
	unsigned int	s;

	i = 0;
	if (n == 0)
		return (1);
	s = n;
	while (s > 0)
	{
		s = s / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa2(int n, int *x)
{
	char			*str;
	int				q;

	q = ft_numbcounter(n);
	*x = q;
	if (!(str = ft_strnew(q)))
		return (NULL);
	while (--q >= 0)
	{
		str[q] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}

void	ft_print_space(int	a, t_qualfrs *ql)
{
	while(a > 0)
	{
		write(1, &SPACE, 1);
		a--;
		ql->countchr++;
	}
}

void	ft_print_zero(int	a, t_qualfrs *ql)
{
	while(a > 0)
	{
		write(1, &ZERO, 1);
		a--;
		ql->countchr++;
	}
}