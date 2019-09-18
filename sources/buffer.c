#include <stdio.h>
#include "double_m.h"


static void foo(char *s_full, unsigned len, unsigned    delta )
{
    unsigned  i;

    if (delta > 0 && len > 0)
    {
        i = 0;
        while (i < delta)
        {
            s_full[len + i] = '0';
            i++;
        }
    }
}

void buf_to_str(uint64_t *buf, char *s_full)  //count_0
{
    char        *s_base;
    unsigned    buflen;
    unsigned    i;
    unsigned    j;
    unsigned    delta;

    buflen = buf[0];
    j = 0;
    i = 0;
	delta = 0;
    while (j < buflen)
    {
        s_base = ft_itoa_base_ll(buf[buflen - j],10);
        j > 0 ? delta = (BASELEN - ft_strlen(s_base)) : 1;
        foo(s_full, i, delta);
        ft_strcpy(&(s_full[i + delta]), s_base);
        i += ft_strlen(s_base) + delta;
        j += 1;
    }
}

/*void    print_buf (unsigned long *buf, unsigned count_0, char c, t_qualfrs *fmt_feature )
{
    char                s_full[buf[0] * BASELEN + count_0 + 2 ];//SIGN ==> +1
    char                s_frac_zero[count_0];
    uint64_t       s_len;

   if (c == 'i')
    {
        fill_int_str(buf, fmt_feature);

        return ;
    }
    if (c == 'f')
    {
        if (fmt_feature->prcs == -1)
            fmt_feature->prcs = 6;
        fill_frac_str(count_0, buf, fmt_feature);
        return;
    }


    //!!!first simbol -- SIGN or space!!!
    s_full[buf[0] * BASELEN + count_0 + 2] = '\0';


    if (count_0 != 0)
    {
        ft_memset(s_frac_zero, '0', count_0);
        write(1, s_frac_zero, count_0);
    }

    ft_memset(s_full, '0', buf[0] * BASELEN);

    if(buf[0] == 1 && buf[1] == 0)
    {
        ft_putstr("0");
        return ;
    }
    else
        buf_to_str(buf, s_full);

    int l = 0;
    while((s_full[l]) == '0')
        l++;
    // printf ("buf_to_str_%s\n", &(s_full[l]));


    write(1, &(s_full[l]), buf[0] * BASELEN - l);

}*/


/*static void put_first_simbol(char* s_full, t_qualfrs *fmt_feature)
{
    if (fmt_feature->flg->plus == -1)
        s_full[0] = '-';
    else if (fmt_feature->flg->plus == 1)
        s_full[0] = '+';
    else if (fmt_feature->flg->plus == 0 && fmt_feature->flg->space)
        s_full[0] = ' ';//put_first_simbol(char* s_full, t_qualfrs *fmt_feature)
    else
        return;
}

void    put_right_int(char *p_start, t_qualfrs *f) // минуса нет
{
    long long   len;

    len = f->width - f->prcs - ft_strlen(p_start); //-'.'
    if (!f->flg->zero)
    {
        if(f->flg->plus != 0)
        {
            len--;
            put_first_simbol(--p_start,f);
        }
        while (len-- > 0)
        {
            *(--p_start) ='$';
        }
    }
    else if (f->flg->zero)
    {
        while(len-- > 1)
        {
            *(--p_start) = '0';
        }
        if(f->flg->plus != 0 || f->flg->space)
        {
            put_first_simbol(--p_start,f);
        }
        f->flg->plus == 0 ? *(--p_start) = '0' : 1;

    }
    ft_putstr(p_start);
}

void    fill_int_str(unsigned long long *buf, t_qualfrs *f)
{
    char            s_full[buf[0] * BASELEN + f->width + 3 ];
    char            *p_start;
    long long       len;

    long long l1 =buf[0] * BASELEN + f->width + 3;
    s_full[buf[0] * BASELEN + f->width + 3 ] = '\0';//3 => sign + '.' + '\0'
    get_buflen(&len, buf);//выше в qualfrs???

    long long l2 =buf[0] * BASELEN + f->width + 1 - buf[0] * BASELEN;
    p_start = &(s_full[buf[0] * BASELEN + f->width + 1 - buf[0] * BASELEN]);
    if (len == 0)
    {
        *p_start = '0';

        s_full[buf[0] * BASELEN + f->width + 2] = '.';
    }
    else
    {
        f->buflen = len;
        //p_start = &(s_full[buf[0] * BASELEN + f->width + 2 - buf[0] * BASELEN]);
        buf_to_str(buf, p_start, BASELEN);
        s_full[buf[0] * BASELEN + f->width + 2] = '.';
        while (*(++p_start) == '0');
    }
    if (((f->width - f->prcs) <= (len + 2)) || f->flg->minus == 1) //len знакового типа !!
    {
        //игнорим width => просто добавить первый символ и сдвинуть start
        if (!(f->flg->plus == 0 && !f->flg->space) )
        {
            put_first_simbol(--p_start,f);
        }
        ft_putstr(p_start);
        return ;
    }
    printf("p_start_%s\n", p_start);
    if (f->flg->minus == 0)
    {
        put_right_int(p_start, f);
        return ;
    }
    if (f->flg->minus == 1) //на целую часть минус не влияет
    {
        put_first_simbol(--p_start, f);
        ft_putstr(p_start);
        return;
    }
}

void fill_frac_str(unsigned count_0, unsigned long long *buf, t_qualfrs *f)
{
    char            s_full[buf[0] * BASELEN + f->width + 1 ];
    char            *p_start;
    long long       len;

    if (count_0 != 0)
    {
        ft_memset(s_full, '0', count_0);
        //write(1, s_frac_zero, count_0);
    }
    ft_memset(s_full, '0', buf[0] * BASELEN);

    if(buf[0] == 1 && buf[1] == 0)
    {
        ft_putstr("0");
        return ;
    }
    else
        buf_to_str(buf, s_full, BASELEN);

    int l = 0;
    while((s_full[l]) == '0')
        l++;
    // printf ("buf_to_str_%s\n", &(s_full[l]));

    write(1, &(s_full[l]), buf[0] * BASELEN - l);
}
*/



/*unsigned ret_buflen(unsigned long long long_num, unsigned long long base)
{
    unsigned buflen;

    buflen = 0;
    while (long_num)
    {
        buflen++;
        long_num /= base;
    }
    return (buflen);
}

unsigned long long *init_buf(unsigned long long long_num, unsigned long long base, unsigned buflen)
{
    unsigned long long *buf;
    unsigned           i;

    if(!(buf = (unsigned long long *)malloc(buflen * sizeof(unsigned long long))))
        return (NULL);
    buf[0] = buflen;
    i = 0;
    while(i++ < buflen)
    {
        buf[i] = long_num % base;
        long_num /= base;
    }
    return (buf);
}*/
