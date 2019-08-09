/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:53:04 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/09 14:48:28 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_how_to_print(t_qualfrs *ql)
{
	if (ql->typs == types[0] || ql->typs == types[1] || ql->typs == types[2])
	{
		if (ql->typs == types[0])
			ft_print_char(ql);
		else if (ql->typs == types[1])
			ft_print_str(ql);
		else if (ql->typs == types[2])
			ft_print_pointer(ql);
	}
	else if (ql->typs == types[3] || ql->typs == types[4])
		ft_print_di(ql);
}

void	ft_zero_struct(t_qualfrs *ql)
{
	t_flag		*fl;
	t_length	*len;

	fl = ql->flg;
	len = ql->len;
	if (ql)
	{
		ql->typs = 0;
		ql->width = 0;
		ql->prcs = 0;
		ql->countnum = 0;
		ql->num = NULL;
		fl = ql->flg;
		if (fl)
		{
			fl->sharp = 0;
			fl->zero = 0;
			fl->plus = 0;
			fl->space = 0;
			fl->minus = 0;
		}
		len = ql->len;
		if (len)
		{
			len->l = 0;
			len->h = 0;
			len->L = 0;
		}
	}
}

void	ft_create_and_free(t_qualfrs *ql, int f)
{
	if (f == 1)
	{
		ql->len = (t_length*)malloc(sizeof(t_length));
		ql->flg = (t_flag*)malloc(sizeof(t_flag));
		ft_zero_struct(ql);
	}
	else if (f == 2)
	{
		free(ql->flg);
		free(ql->len);
	}
}

int		ft_printf(const char *format, ...)
{
	t_qualfrs	qual;
	char	*c;

	qual.countchr = 0;
	ft_create_and_free(&qual, 1);
	c = (char*)format;
	va_start(qual.ap, format);
	while (c != NULL && *c)
	{
		if (!(c = ft_print_format(c, &qual)))
			continue ;
		c = ft_search_syntax(c, &qual);
		ft_how_to_print(&qual);
		ft_zero_struct(&qual);
	}
	va_end(qual.ap);
	return (qual.countchr);
}

int		main(int ac, char **av)
{
	int	a = 7;
	char	b[] = "qwerty";
	char	c;
	int t = 4356;

	c = '1';
	// ft_printf("%3523%40p\n", b, b);
	ft_printf("%d", t);
	//printf("%-10d \n", a);
	// a = ft_strchr(b, 't') - b;
	// printf("range =%c erttert", c);

	return (0);
}
