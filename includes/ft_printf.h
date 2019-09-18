/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:22:54 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/21 22:20:12 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "ft_printf.h"
# include "../libft/libft.h"
# include <stdio.h>
# define TYPES "cspdiouxXegfC%"
# define ALLFLG "#0-+ "
# define SPACE " "
# define ADDRESS "0x"
# define ADDRESS2 "0X"
# define ZERO "0"
# define PLUS "+"
# define MINUS "-"
# define NULLPRINT "(null)"
# define INF_NAN {"NAN", "nan", "INF", "inf"}

typedef struct				s_qualfrs
{
		int					countchr;
		int					signum;
		int					typs;
		int					width;
		int					prcs;
		char				*num;
		char				*sformat;
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



int		ft_flags(char *format, t_qualfrs *ql);
int		ft_width(char *frm, t_qualfrs *ql);
int		ft_precision(char *frm, t_qualfrs *ql);
int		ft_length(char *frm, t_qualfrs *ql);
char	*ft_types(char *frm, t_qualfrs *ql);


void	ft_print_di(t_qualfrs *ql);
void	ft_print_di_2(t_qualfrs *ql);
void	ft_print_di_neg(t_qualfrs *ql);
void	ft_print_di_neg2(t_qualfrs *ql);
void	ft_print_di_neg3(t_qualfrs *ql);
void	ft_print_di_neg4(t_qualfrs *ql);
void	ft_print_di_pos(t_qualfrs *ql);
void	ft_print_di_pos2(t_qualfrs *ql);
void	ft_print_di_pos3(t_qualfrs *ql);
void	ft_print_di_pos4(t_qualfrs *ql);
void	ft_print_number(t_qualfrs *ql);

char	*ft_sign_lenchoose(t_qualfrs *ql);
char	*ft_sign_lenchoose2(t_qualfrs *ql);

char	*ft_unsign_lenchoose(t_qualfrs *ql);
char	*ft_unsign_lenchoose2(t_qualfrs *ql);

void	ft_print_ox(t_qualfrs *ql);
char	*ft_len_ox2(unsigned long long numb, t_qualfrs *ql);
char	*ft_len_ox(unsigned long long numb, t_qualfrs *ql);
void	ft_print_sharp(t_qualfrs *ql);
void	ft_print_ox2(t_qualfrs *ql);
void	ft_print_xo(t_qualfrs *ql);
void	ft_print_xo2(t_qualfrs *ql);
void	ft_print_xo3(t_qualfrs *ql);
void	ft_print_xo4(t_qualfrs *ql);

void	ft_print_u(t_qualfrs *ql);
void	ft_print_u2(t_qualfrs *ql);
void	ft_print_u_1(t_qualfrs *ql);
void	ft_print_u_2(t_qualfrs *ql);
void	ft_print_u_3(t_qualfrs *ql);


char		*ft_itoa2(unsigned long long int n, int *x);
void		ft_print_space(int	a, t_qualfrs *ql);
void		ft_print_zero(int	a, t_qualfrs *ql);
char		*ft_10_to_8(unsigned long long x, t_qualfrs *ql);
char		*ft_10_to_16(unsigned long long x, t_qualfrs *ql);
void		ft_search_syntax(char *format, t_qualfrs *qual);
void		ft_print_pointer(t_qualfrs *ql);
void		ft_print_pointer2(t_qualfrs *ql);
void		ft_print_str(t_qualfrs *ql);
void		ft_print_char(t_qualfrs *ql);
char		*ft_print_format(char *as, t_qualfrs *qual);

void	ft_color(t_qualfrs *ql);
void	ft_zero_struct(t_qualfrs *ql);
void	ft_zero_struct2(t_qualfrs *ql);
void	ft_without_typs(t_qualfrs *ql);
void	ft_print_percent(t_qualfrs *ql);

#endif
