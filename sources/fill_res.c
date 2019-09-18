//
// Created by Buster Charity on 2019-08-28.
//
#include "double_m.h"

char 		*fill_res_f(char* res_str, char *s_full, t_qualfrs *fmt)
{
    long long 	tmp;
    char	*p;

	p = &(res_str[fmt->ld->totallen - 1]);
	if (fmt->flg->minus && (tmp = fmt->ld->delta) > 0)
	{
		while (tmp-- > 0)
		{
			p--;
			*p = ' ';
		}
	}
	while (fmt->ld->ovrld-- > 0)
	{
		p--;
		*p = '0';
	}
	tmp = ft_strlen(s_full) - 1;
	while (tmp >= 0)
	{
		p--;
		*p = s_full[tmp];
		tmp--;
	}
	printf("p_%s*\n", p);
	return(p);
}

char 		*fill_res_e(char* res_str,  t_qualfrs *fmt)
{
    long long 	tmp;
    char	*p;

    p = (res_str);
    if (fmt->flg->minus && (tmp = fmt->ld->delta) > 0)
    {
        while (tmp-- > 0)
        {
            p--;
            *p = ' ';
        }
    }
    while (fmt->ld->ovrld-- > 0)
    {
        p--;
        *p = '0';
    }
  /*  tmp = ft_strlen(s_full) - 1;
    while (tmp >= 0)
    {
        p--;
        *p = s_full[tmp];
        tmp--;
    }*/
  //  printf("pe_%s*\n", p);
    return(p);
}
