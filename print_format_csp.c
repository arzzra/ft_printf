/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_csp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:47:10 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/09 14:47:51 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_format(char *as, t_qualfrs *qual)
{
	size_t	r;
	char	*str;
	char	*sa;

	if (!(sa = ft_strchr(as, '%')))
	{
		write(1, as, ft_strlen(as));
		return (NULL);
	}
	r = sa - as;
	if (sa[1] == '%' )
	{
		str = ft_strncpy(ft_strnew(r + 1), as, r + 1);
		qual->countchr += write(1, str, r + 1);
		free (str);
		sa += 2;
		return (ft_print_format(sa, qual));
	}
	else if (r > 0)
	{
		str = ft_strncpy(ft_strnew(r), as, r);
		qual->countchr += write(1, str, r);
		free (str);
		sa++;
		return (sa);
	}
	return (++sa);
}


void	ft_print_char(t_qualfrs *ql)
{
	t_flag	*fl;
	char	c;

	fl = ql->flg;
	if (ql->width > 0)
	{
		if (fl->minus > 0)
		{
			ql->countchr++;
			c = va_arg(ql->ap, int);
			write(1, &c, 1);
			ft_print_space(ql->width - 1, ql);
		}
		else
		{
			ql->countchr++;
			c = va_arg(ql->ap, int);
			ft_print_space(ql->width - 1, ql);
			write (1, &c, 1);
		}
	}
	else
	{
		ql->countchr++;
		c = va_arg(ql->ap, int);
		write (1, &c, 1);
	}
}

void	ft_print_str(t_qualfrs *ql)
{
	t_flag	*fl;
	char	*str;
	int		y;

	fl = ql->flg;
	if (ql->width > 0)
	{
		if (fl->minus > 0)
		{
			str = va_arg(ql->ap, char*);
			y = ft_strlen(str);
			ql->countchr += y;
			write (1, str, y);
			ft_print_space(ql->width - y, ql);
		}
		else
		{
			str = va_arg(ql->ap, char*);
			y = ft_strlen(str);
			ql->countchr += y;
			ft_print_space(ql->width - y, ql);
			write (1, str, y);
		}
	}
	else
	{
		str = va_arg(ql->ap, char*);
		y = ft_strlen(str);
		ql->countchr += y;
		write (1, str, y);
	}
}

void	ft_print_pointer2(t_qualfrs *ql, char *adr)
{
	t_flag	*fl;

	fl = ql->flg;
	if (ql->width > 0)
	{
		if (fl->minus)
		{
			ql->countchr += write(1, &addres, 2);
			ql->countchr += write(1, adr, 12);
			ft_print_space(ql->width - 12, ql);
		}
		else if (fl->zero)
		{
			ql->countchr += write(1, &addres, 2);
			ft_print_zero(ql->width - 14, ql);
			ql->countchr += write(1, adr, 12);
		}
		else
		{
			ft_print_space(ql->width - 14, ql);
			ql->countchr += write(1, &addres, 2);
			ql->countchr += write(1, adr, 12);
		}
	}
	else
	{
		ql->countchr += write(1, &addres, 2);
		ql->countchr += write(1, adr, 12);
	}
}

void	ft_print_pointer(t_qualfrs *ql)
{
	char	*poin;
	unsigned long long tr;
	int		i;

	poin = va_arg(ql->ap, char*);
	tr = (unsigned long long)poin;
	i = 11;
	if (!(poin = ft_strnew(12)))
		return ;
	while (i >= 0)
	{
		poin[i] = (tr % 16 < 10) ? tr % 16 +'0' : tr % 16 - 10 + 'a';
		i--;
		tr /= 16;
	}
	ft_print_pointer2(ql, poin);
	free(poin);
}