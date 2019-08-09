/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:22:54 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/09 14:52:09 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "ft_printf.h"
# include "libft/libft.h"
# define types "cspdiouxXegf"
# define allflags "#0-+ "
# define SPACE " "
# define addres "0x"
# define ZERO "0"
# define PLUS "+"
# define MINUS "-"

typedef struct				s_qualfrs
{
		int					countchr;
		int					typs;
		int					width;
		int					prcs;
		void				*num;
		int					countnum;
		struct s_flag		*flg;
		struct s_length		*len;
		va_list				ap;
}							t_qualfrs;

typedef struct		s_flag
{
		int			sharp;
		int			zero;
		int			minus;
		int			plus;
		int			space;
}					t_flag;


typedef struct		s_length
{
		int			l;
		int			h;
		int			L;
}					t_length;

typedef struct		s_usd
{
		u_int64_t	buffer;
		int			n;
		struct	s_usd		*next;
}					t_usd;


char		*ft_itoa2(int n, int *x);
void		ft_print_di(t_qualfrs *ql);
void		ft_print_space(int	a, t_qualfrs *ql);
void		ft_print_zero(int	a, t_qualfrs *ql);
char		*ft_10_to_8(u_int64_t x, char f);
char	*ft_search_syntax(char *format, t_qualfrs *qual);
void	ft_print_pointer(t_qualfrs *ql);
void	ft_print_pointer2(t_qualfrs *ql, char *adr);
void	ft_print_str(t_qualfrs *ql);
void	ft_print_char(t_qualfrs *ql);
char	*ft_print_format(char *as, t_qualfrs *qual);
# endif
