/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:53:04 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/03 07:30:32 by cdemetra         ###   ########.fr       */
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
		flag->plus = (*fls == allflags[2]) ? allflags[2] : flag->plus;
		flag->minus = (*fls == allflags[3]) ? allflags[3] : flag->minus;
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
			ql->width = ft_atoi(frm);
			while (ql->width > 0 && frm[i] >= '0' && frm[i] <= '9')
				i++;
			return (i);
		}
	}
	else
		return (0);
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

char	*ft_search_syntax(char *format, t_qualfrs *qual)
{
	char	*ser;
	int		i;
	char 	*tps;
	int		fls;

	i = 0;
	ser = NULL;
	while (!(ser = ft_strchr(types, format[i])))
	{
		i += ft_flags(&(format)[i], qual);
		i += ft_width(&(format)[i], qual);
		printf("width:%d\n", qual->width);
		i += ft_precision(&(format)[i], qual);
		i += ft_length(&(format)[i], qual);
		printf("prec:%d\n", qual->prcs);
		printf("i:%d\n", i);
	}
	qual->typs = *ser;
	printf("types:%c\n", format[i]);
	return (&(format)[i + 1]);
}

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
}

void	ft_zero_struct(t_qualfrs *ql)
{
	t_flag		*fl;
	t_length	*len;

	if (ql)
	{
		ql->typs = 0;
		ql->width = 0;
		ql->prcs = 0;
		fl = ql->flg;
		if (fl)
		{
			fl->sharp = 0;
			fl->zero = 0;
			fl->plus = 0;
			fl->space = 0;
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
	}
	va_end(qual.ap);
	return (qual.countchr);
}

int		main(int ac, char **av)
{
	int	a = 45;
	char	b[] = "qwerty";
	char	c;

	c = '1';
	// ft_printf("%3523%40p\n", b, b);
	printf("%3kjk7%40p\n", b);
	// a = ft_strchr(b, 't') - b;
	// printf("range =%c erttert", c);

	return (0);
}
