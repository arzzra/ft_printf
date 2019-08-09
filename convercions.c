/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convercions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:30:19 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/08 20:38:37 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_10_to_8(u_int64_t x, t_qualfrs *ql)
{
	char	*num8;
	int		i;
	u_int64_t	g;

	g = x;
	i = 0;
	while (g /= 8)
		i++;
	ql->countnum;
	if (!(num8 = ft_strnew(i)))
		return(NULL) ;
	while (i >= 0)
	{
		poin[i] = tr % 8 +'0';
		i--;
		tr /= 8;
	}
	return(num8);
}

char	*ft__10_to_16(u_int64_t x, t_qualfrs *ql, int upr)
{
	char	*num8;
	int		i;
	u_int64_t	g;
	char up;

	g = x
	i = 0;
	while (g /= 16)
		i++;
	ql->countnum;
	if (!(num8 = ft_strnew(i)))
		return(NULL) ;
	up = upr == 0 ? 'a' : 'A';
	while (i >= 0)
	{
		num8[i] = (tr % 16 < 10) ? tr % 16 +'0' : tr % 16 - 10 + up;
		i--;
		tr /= 16;
	}
	return(num8);
}


void	ft_putcharutf8(char c)
{
	char			wr;
	unsigned char	c2;

	c2 = (unsigned char)c;
	if (c2 < 0)
		return ;
	if (c2 > 0x7F)
	{
		wr = (c2 >> 6) | 0xC0;
		write(1, &wr, 1);
		wr = c2 & 0xbf;
		write(1, &wr, 1);
	}
	else
		write(1, &c2, 1);
}
