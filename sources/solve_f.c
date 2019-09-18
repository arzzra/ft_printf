//
// Created by Buster Charity on 2019-08-23.
//
#include "double_m.h"

char *solve_f(uint64_t *p_int, uint64_t *p_frac, char **res_str, t_qualfrs *fmt)
{
    char			*si;
    char			*sf;
    long long		totallen;
    int 			dt;

    //total length + '.'(?)
//=================================================================================
    totallen = get_buflen(p_int) + 1 + fmt->ld->ovrld + fmt->ld->realprec ;// int part's length + '\0'+ overload(prec > 16383)

    if(fmt->ld->realprec > 0 || fmt->flg->sharp) //если точность больше 0 или есть #
	{
		totallen++; // + '.'
		if(fmt->flg->plus != 0 || fmt->flg->space == 1)
		{
			totallen++; //+ sign
		}
	}

	(dt = fmt->width - totallen + 1) > 0 ? totallen += dt : 1;
	fmt->ld->delta = dt;
    fmt->ld->totallen = totallen;
//=================================================================================
	//printf("total_len_%lld\n", totallen);
	*res_str = (char*)malloc(totallen * sizeof(char));
	(*res_str)[totallen - 1] = '\0';
	si = *res_str;

    sf = save_frac_part(*res_str, p_frac, fmt);
	printf("sf_%s*\n", sf);

	si = save_int_part(*res_str, p_int, fmt);
	printf("si_%s*\n", si);
	printf("point_%c*\n", (*res_str)[sf - si]);

	(*res_str)[sf - si] = '.';

	//printf("*%s*\n", (*res_str));
    //printf("*");
    write(1,"*", 1);
	write(1,(*res_str), totallen - 1);

    printf("*\n");

	return (NULL);
}

void	put_first_simbol(char **p, t_qualfrs *fmt)
{
	if (fmt->flg->plus > 0)
		**p = '+';
	else if(fmt->flg->plus < 0)
		**p = '-';
	else if(fmt->flg->space)
	{
		**p = '$';
	}
	else
		return;
    (*p)++;

}

char    *save_int_part(char *res_str, uint64_t *buf, t_qualfrs *fmt)
{
	char	*p;

	p = res_str;
		if (fmt->flg->zero && !fmt->flg->minus)
		{
            if(fmt->flg->plus != 0 || fmt->flg->space == 1)
                put_first_simbol(&p, fmt);
            if(fmt->ld->delta > 0)
			{
				ft_memset(p, '0', fmt->ld->delta);
				p += fmt->ld->delta;
			}
		}
		else if (!fmt->flg->zero && !fmt->flg->minus)
		{
			if(fmt->ld->delta > 0)
			{
				ft_memset(p, ' ', fmt->ld->delta);
				p += fmt->ld->delta;
			}
			put_first_simbol(&(p), fmt);
		}
		else
		    if(fmt->flg->plus != 0 || fmt->flg->space == 1)
                 put_first_simbol(&p, fmt);

		buf_to_str(buf, p);
    	return(res_str);
}

long long	get_buflen(uint64_t *buf)
{
	unsigned long	last_el;
	long long		buflen;

	buflen = 0;
	last_el = buf[buf[0]];
	buflen = (buf[0] - 1) * BASELEN;
	if (buf[0] == 1 && buf[1] == 0)
		return (1);
	while (last_el)
	{
		last_el /= 10;
		(buflen)++;
	}
	return (buflen);
}