/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:22:54 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/03 07:22:53 by cdemetra         ###   ########.fr       */
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

typedef struct				s_qualfrs
{
		int					countchr;
		int					typs;
		int					width;
		int					prcs;
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

# endif
