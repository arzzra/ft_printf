/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:53:02 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/21 22:37:06 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <math.h>

void    print_bits(size_t size, void *ptr, char space)
{
   unsigned char	*b;
   unsigned char	byte;
   int				i;
   int				j;

   b = (unsigned char*)ptr;
   i = size - 1;
   j = 7;
   while (i >= 0)
   {
       while (j >= 0)
       {
           byte = (b[i] >> j) & 1;
		   printf("%c",(byte + '0'));
           j--;
       }
       if (space == 1)
           printf(" ");
       j = 7;
       i--;
   }
   printf("\n");
}

void	ft_print_nan_inf(t_qualfrs *ql, int f)
{
	if (f == 1)
	{
		if (ql->typs >= 65 && ql->typs <= 90)
			ql->countchr += write(1, INF_NAN[0], 3);
		else
			ql->countchr += write(1, INF_NAN[1], 3);
	}
	else if (f == 2)
	{
		if (ql->typs >= 65 && ql->typs <= 90)
			ql->countchr += write(1, INF_NAN[2], 3);
		else
			ql->countchr += write(1, INF_NAN[3], 3);
	}
}

int		ft_inf_nan(char *s_int, t_qualfrs *ql)
{
	int i;

	i = 0;
	while (s_int[i] == '1' && i < 15)
		i++;
	if (i != 14)
		return (0);
	else if (s_int[i] == '1')
	{
		while (s_int[i] == '0' && s_int[i])
			i++;
		if (i < 64)
			ft_print_nan_inf(ql, 1);
		else
		{
			if (s_int[0] == '0')
				ql->countchr += write(1, &MINUS, 1);
			ft_print_nan_inf(ql, 2);
		}
		return (1);
	}
	return (0);
}

int main()
{
	long double gg;

	gg = INFINITY;
	printf("double = %+LE\n", gg);
	print_bits(10, &gg, 0);
	return (0);
}
