/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:45:01 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/09 14:45:50 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags(char *format, t_qualfrs *ql)
{
	int		i;
	char	*fls;
	t_flag	*flag;

	flag = ql->flg;
	i = 0;
	while ((fls = ft_strchr(allflags, format[i])))
	{
		flag->sharp = (*fls == allflags[0]) ? allflags[0] : flag->sharp;
		flag->zero = (*fls == allflags[1]) ? allflags[1] : flag->zero;
		flag->minus = (*fls == allflags[2]) ? allflags[2] : flag->minus;
		flag->plus = (*fls == allflags[3]) ? allflags[3] : flag->plus;
		flag->space = (*fls == allflags[4]) ? allflags[4] : flag->space;
		i++;
	}
	return (i);
}

int		ft_width(char *frm, t_qualfrs *ql)
{
	int		i;

	i = 0;
	if (*frm == '*')
	{
		ql->width = va_arg(ql->ap, int);
		return (1);
	}
	else
	{
		ql->width = ft_atoi(frm);
		while (ql->width > 0 && frm[i] >= '0' && frm[i] <= '9')
			i++;
		return (i);
	}
}

int		ft_precision(char *frm, t_qualfrs *ql)
{
	int		i;

	i = 0;
	if (*frm == '.')
	{
		i++;
		if (frm[i] == '*')
		{
			ql->prcs = va_arg(ql->ap, int);
			return (2);
		}
		else
		{
			ql->prcs = ft_atoi(&(frm)[i]);
			while (ql->prcs > 0 && frm[i] >= '0' && frm[i] <= '9')
				i++;
			return (i);
		}
	}
	else
		return (i);
}

int		ft_length(char *frm, t_qualfrs *ql)
{
	t_length	*len;

	len = ql->len;
	if (*frm == 'l')
	{
		len->l = 1;
		len->l = (frm[1] == 'l') ? len->h + 1 : 1;
		return (len->l);
	}
	else if (*frm == 'h')
	{
		len->h = 1;
		len->h = (frm[1] == 'h') ? len->h + 1 : 1;
		return (len->h);
	}
	else if (*frm == 'L')
	{
		len->L = 1;
		return (1);
	}
	else
		return (0);
}

char	*ft_types(char *frm, t_qualfrs *ql)
{
	char	*ser;

	if ((ser = ft_strchr(types, *frm)))
	{
		ql->typs = *ser;
		return (ser);
	}
	else
		return (NULL);
}

char	*ft_search_syntax(char *format, t_qualfrs *qual)
{
	char	*ser;
	int		i;
	int		fls;

	i = 0;
	fls = 0;
	ser = NULL;
	while (!ser)
	{
		i += ft_flags(&(format)[i], qual);
		i += ft_width(&(format)[i], qual);
		i += ft_precision(&(format)[i], qual);
		i += ft_length(&(format)[i], qual);
		ser = ft_types(&(format)[i], qual);
		fls++;
	}
	i++;
	return (&(format)[i]);
}