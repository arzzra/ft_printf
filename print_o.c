/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:26:24 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/08 20:02:45 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_o(t_qualfrs *ql)
{
	u_int64_t	a;
	t_flag		*fl;
	t_length	*len;

	a = va_arg(ql->ap, unsigned_int);
	ql->num = ft_10_to_8(a);
	if (ql->width > ql->countnum)
	{
		if (fl->minus)
		{
			if (numb < 0)
				ft_print_di_neg(ql);
			else
				ft_print_di_pos(ql);
		}
		else
		{
			if (fl->zero && ql->prcs == 0)
			{
				if (numb < 0)
					ft_print_di_neg2(ql);
				else
					ft_print_di_pos2(ql);
			}
			else
			{
				if (numb < 0)
					ft_print_di_neg3(ql);
				else
					ft_print_di_pos3(ql);
			}
		}
	}
	else
	{
		if (numb < 0)
			ft_print_di_neg3(ql);
		else
			ft_print_di_pos3(ql);
	}
}
