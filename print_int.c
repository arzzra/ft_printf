/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:47:10 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/08 14:24:19 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di_neg(t_qualfrs *ql)
{
	t_flag *fl;
	t_length *len;

	fl = ql->flg;
	len = ql->len;
	ql->countchr += write(1, &MINUS, 1);
	if (ql->prcs > ql->countnum)
	{
		ft_print_zero((ql->prcs -  ql->countnum), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
		ft_print_space((ql->width - (ql->prcs - ql->countnum) - ql->countnum - 1), ql);
	}
	else
	{
		ql->countchr += write(1, ql->num, ql->countnum);
		ft_print_space(ql->width - ql->countnum - 1, ql);
	}
}

void	ft_print_di_pos(t_qualfrs *ql)
{
	t_flag *fl;
	t_length *len;
	int		plus;

	fl = ql->flg;
	len = ql->len;
	plus = fl->plus > 0 ? 1 : 0;
	if (fl->space > 0 && fl->plus == 0)
		ft_print_space(1, ql);
	if (fl->plus > 0)
		ql->countchr += write(1, &PLUS, 1);
	if (ql->prcs > ql->countnum)
	{
		ft_print_zero((ql->prcs -  ql->countnum), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
		ft_print_space((ql->width - (ql->prcs - ql->countnum) - ql->countnum - plus), ql);
	}
	else
	{
		ql->countchr += write(1, ql->num, ql->countnum);
		ft_print_space(ql->width - ql->countnum  - plus, ql);
	}
}

void	ft_print_di_neg2(t_qualfrs *ql)
{
	t_flag *fl;
	t_length *len;

	ql->countchr += write(1, &MINUS, 1);
	if (ql->width > ql->countnum)
	{
		ft_print_zero((ql->width -  ql->countnum - 1), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
	else
		ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_di_pos2(t_qualfrs *ql)
{
	t_flag *fl;
	t_length *len;
	int		plus;

	fl = ql->flg;
	len = ql->len;
	plus = fl->plus > 0 ? 1 : 0;
	if (fl->space > 0 && fl->plus == 0)
		ft_print_space(1, ql);
	if (fl->plus > 0)
		ql->countchr += write(1, &PLUS, 1);
	if (ql->width > ql->countnum)
	{
		ft_print_zero((ql->width -  ql->countnum - plus), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
	else
		ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_di_neg3(t_qualfrs *ql)
{
	if (ql->prcs > ql->countnum)
		ft_print_space((ql->width - (ql->countnum + 1) - (ql->prcs - ql->countnum)), ql);
	else
		ft_print_space((ql->width - (ql->countnum + 1)), ql);
	ql->countchr += write(1, &MINUS, 1);
	ft_print_zero((ql->prcs - ql->countnum), ql);
	ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_di_pos3(t_qualfrs *ql)
{
	t_flag *fl;
	t_length *len;
	int		plus;

	fl = ql->flg;
	len = ql->len;
	plus = fl->plus > 0 ? 1 : 0;
	if (ql->prcs > ql->countnum)
		ft_print_space((ql->width - (ql->countnum + plus) - (ql->prcs - ql->countnum)), ql);
	else
		ft_print_space((ql->width - (ql->countnum + plus)), ql);
	if (fl->space > 0 && fl->plus == 0 && ql->width < ql->countnum)
		ft_print_space(1, ql);
	if (fl->plus > 0)
		ql->countchr += write(1, &PLUS, 1);
	ft_print_zero((ql->prcs -  ql->countnum), ql);
	ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_di_neg4(t_qualfrs *ql)
{
	ql->countchr += write(1, &MINUS, 1);
	ft_print_zero((ql->prcs - ql->countnum), ql);
	ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_di_pos4(t_qualfrs *ql)
{
	t_flag *fl;
	t_length *len;
	int		plus;

	fl = ql->flg;
	len = ql->len;
	plus = fl->plus > 0 ? 1 : 0;
	if (fl->space > 0 && fl->plus == 0)
		ft_print_space(1, ql);
	if (fl->plus > 0)
		ql->countchr += write(1, &PLUS, 1);
	ft_print_zero((ql->prcs -  ql->countnum), ql);
	ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_di(t_qualfrs *ql)
{
	int		numb;
	int		count;
	char	*num;
	t_flag	*fl;
	t_length	*len;

	fl = ql->flg;
	len = ql->len;
	//if (len->l > 0 || len->h > 0)

	numb = va_arg(ql->ap, int);
	ql->num =(void*) ft_itoa2(numb, &count);
	ql->countnum = count;
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
