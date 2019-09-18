//
// Created by Buster Charity on 2019-09-07.
//
#include "double_m.h"

long long number_pow(long long num)
{
    int i;
    long long d;

    d = num;
    if (d < 0)
        d *= -1;
    i = 0;
    while (d)
    {
        d /= 10;
        i++;
    }
   // printf("\nnumber_pow_e_%d\n", i);
    return (i);
}

char *solve_e(uint64_t *p_int, uint64_t *p_frac, char **res_str, t_qualfrs *fmt)
{
	char        *si;
	char        *sf;
    char        *p;
    long long   tmp;
	long long   totallen;
	int         dt;

//=================================================================================
    totallen = 4; // first_int + e+/- + '\0'
    fmt->ld->sf_index = 2;// e+/-

    if(fmt->ld->realprec > 0 || fmt->flg->sharp)
	{
		totallen++; // + '.'
        fmt->ld->sf_index++;

	    totallen += fmt->ld->realprec;
        fmt->ld->sf_index += fmt->ld->realprec;
	}
    if(fmt->flg->plus != 0 || fmt->flg->space == 1) //sign
        totallen++;
//=====================================
	//число после е
    fmt->ld->e = 0;
	if(p_int[0] == 1 && p_int[1] == 0 && fmt->ld->realprec != 0)
    {
	    fmt->ld->e = -fmt->ld->count_0 - 1;
    }
	else
    {
        fmt->ld->e = get_buflen(p_int) - 1;
    }
    //посчитать цифры после е+/-
    tmp = number_pow((size_t)fmt->ld->e);
	if(tmp <= 1)
	    tmp = 2;
	totallen += tmp;
    fmt->ld->sf_index += tmp;
//===============================
    (dt = fmt->width - totallen + 1) > 0 ? totallen += dt : 1;
    fmt->ld->delta = dt;
    fmt->ld->totallen = totallen;

    fmt->ld->sf_index = totallen - fmt->ld->sf_index  - 1;
//=================================================================================
    //printf("total_len_%lld\n", totallen);
    *res_str = ft_memalloc(totallen * sizeof(char));
    (*res_str)[totallen - 1] = '\0';
    si = *res_str;

    sf = &(si[fmt->ld->sf_index]);

    save_frac_part_e(sf, p_int,p_frac,fmt);
    printf("sf_%s*\n\n", sf);

    //проверить  fmt->ld->iflg, если == 0 =>первая цифра из frac (fflg)
    si = save_int_part_e(si, p_int, fmt);

    //printf("si_%s*\n", si);

    write(1,"*", 1);
    write(1,(*res_str), totallen - 1);
    printf("*\n");

    return (NULL);

}

char     *save_frac_part_e(char *sf, uint64_t *p_int, uint64_t *p_frac, t_qualfrs *fmt)
{
    char			*s_full;//[fmt->ld->totallen + BASELEN + 8];
    size_t		len;

    s_full = sf;
    s_full[0] = '\0';
    fmt->ld->carry = 0;

    if(fmt->ld->iflg == 0 && fmt->ld->fflg == 0)
    {
        fmt->ld->realprec = -1;
        fill_e_end(s_full,fmt);
        //  printf("s_full_before_res_%s*\n", s_full);
        return (fill_res_e(sf,fmt));
        //00.000
    }
    if(fmt->ld->iflg == 1) //есть целая часть
    {
        if (p_int[0] * BASELEN > fmt->ld->totallen)
        {
            p_int = cut_buf(p_int,fmt->ld->totallen + 7);
        }
        buf_to_str(p_int, s_full);
        printf("s_full_1_%s*\n", s_full);
    }
//*************************************************
    len = ft_strlen(s_full);
        if (fmt->ld->e >= 0)
        {
            ft_memset(&(s_full[len]), '0', fmt->ld->count_0);
            len += fmt->ld->count_0;
        }
        buf_to_str(p_frac, &(s_full[len]));
    //printf("s_full_2_%s*\n", s_full);

        fmt->ld->tmp = s_full[0]; // сохранить первую цифру
        s_full[0] = '.';

    //printf("s_full_before_round_%s*\n", s_full);
        round_line(&(s_full[1]), fmt);

//*************************************************

        fill_e_end(s_full,fmt);
      //  printf("s_full_before_res_%s*\n", s_full);
    return (fill_res_e(sf,fmt));
}


void    fill_e_end(char *s_full, t_qualfrs *fmt)
{
    char            *p;
    long long		i;

    p = &s_full[fmt->ld->realprec + 1];
    *(p) = 'e';
    p++;
    if (fmt->ld->e >= 0)
        *(p) = '+';
    else
        *(p) = '-';
    p++;
    if (fmt->ld->e < 0)
        fmt->ld->e *= -1;

    i = number_pow((long long) fmt->ld->e);
    if (i < 2)
    {
        i == 0 ? i++ : 1;
        *(p) = '0';
        p++;
    }

    p += i;
    *(p) = '\0';

   // printf("i_%lld*\n", i);
   if (fmt->ld->e == 0)
       *(--p) =  48;
    while (fmt->ld->e)
    {
        *(--p) = (fmt->ld->e % 10) + 48;
        fmt->ld->e /= 10;
    }
}


uint64_t *cut_buf(uint64_t *buf, long long len)
{
    long long  lf;
    long long   n;

    if (buf[0] == 1)
        return (buf);
    n = 0;
    lf = number_pow((long long)buf[buf[0]]); //степень первого элемента числа
    len -= lf;
    if (len  > 0)
    {
        n = (len) / (BASELEN);
        if ((len) % BASELEN > 0)
            n++;
    }
    n++;
    buf[buf[0] - n] = n;
    return ( &(buf[buf[0] - n]));
}
