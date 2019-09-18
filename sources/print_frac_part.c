
/*#include "double_m.h"

unsigned long       *save_frac_part(char *s_frac, unsigned long *buf,  t_qualfrs *fmt_feature)
{
    unsigned long res[2000];
    unsigned long  buf_2n[2001];
    unsigned i;
    int prec;

    prec = fmt_feature->prcs;


   convert_string(buf, s_frac);
    pow_of_num(buf_2n, 63 - fmt_feature->ld->exp, 2);

    div_mod_l(buf, buf_2n, res);
    (i = prec) < 6 ? i = 6 : 1;
    while (i + 1 > 0) // *10 - явные числа после зпт
    {
         mul_s(buf, 10);
         i--;
    }
    div_mod_l(buf, buf_2n, res);
    copy_buf_ull(res, buf);
    return (buf);
    //print_buf(res, count_0,'f', fmt_feature);
}

void pow_of_num(unsigned long *buf_n, unsigned long  exp, unsigned num)
{
    buf_n[0] = 1;
    buf_n[1] = 1;

    while (exp > 0)
    {
        mul_s(buf_n, num);
        exp--;
    }
}

unsigned skip_first_last_zeros(char *s_part, unsigned *maxpow)
{
    char                *start_s; // пропустить нули в начале строки(для дробной части)
    unsigned            i;

    i = 0;
    start_s = s_part;
    while(s_part[(*maxpow) - i] == '0')//пропустить младшие "0"
    {
        i++;
    }
    while (*(start_s) != '1')//пропустить старшие "0"
    {
        start_s++;
        (*maxpow)--;
    }
    return (i);
}

void convert_string(unsigned  long *buf, char *s_part)
{
    unsigned            maxpow;
    unsigned            i;
    unsigned long       buf_2n[2000];
    long long           maxindx;

    buf[0] = 1;
    buf[1] = 0;
    maxindx = ft_strlen(s_part) - 1;
    maxpow = maxindx;
    i = skip_first_last_zeros(s_part, &maxpow);
    pow_of_two(buf_2n, i);//сохраняю начальную степень 2
    while(i <= maxpow) //перевод в десятичный массив
    {
        if (i == 0)
            buf[1] = 0;
        if (s_part[maxindx - i] == '1')
            add(buf, buf_2n);
        mul_s(buf_2n, 2);
        i++;
    }
}

unsigned start_index(char *s_part)
{
    unsigned start_i;

    start_i = 1;
    while (*s_part == '0')
    {
        start_i++;
        s_part++;
    }
    printf("\nstart_index = %u\n", start_i);
    return(start_i);
}


void    copy_buf_ull(const unsigned  long *src, unsigned long *dst)
{
    int i;

    i = src[0];
    while (i >= 0)
    {
        dst[i] = src[i];
        i--;
    }
}*/


/*void print_last_zero(int prec)
{
    char s[prec + 1];

    ft_memset(s, '0', prec + 1);
    s[0] = '.';
    write(1, s, prec + 1);
}*/


/*oid    keep_mod(unsigned long long *buf, unsigned long long base, unsigned baselen, long long exp)
{
    unsigned long long  short_two;
    unsigned long long res[1001];
    unsigned i;
    unsigned n;
    unsigned s;

    short_two = 65536;
    s = 0;
    i = 63 - exp;
    n = i / 16;
    i = i - n * 16;
    while (n > 0 && s == 0)
    {
        s = mod(buf, short_two, res, base);
        while (n == 0 && i > 0 && s == 0)
        {
            s = mod(buf, short_two, res, base);
            i--;
        }
        n--;
    }
    printf("keep_mod:\n");
    for (unsigned n = buf[0]; n >= 1; n--)
    {
        printf("_%llu_",buf[n]);
    }
    printf("\n");
}

*/


/*void    div_mod(unsigned long long *buf, unsigned long long *res, unsigned long long base, unsigned baselen, long long exp)
{
    unsigned long long  short_two;
    unsigned i;
    unsigned n;

    short_two = 65536;
    i = 63 - exp;
    n = i / 16;
    i = i - n * 16;

    while (n > 0 )
    {
        div_s(buf, short_two, res, base);
        while (n == 0 && i > 0 )
        {
            div_s(buf, short_two, res, base);
            i--;
        }
        n--;
    }
    printf("div_mod:\n");
    for (unsigned n = buf[0]; n >= 1; n--)
    {
        printf("_%llu_",buf[n]);
    }
    printf("\n");
    while (i >= 1)//деление на 2^(63-e)
 {
     div_s(buf, 2, res, base);
     while (buf[buf[0]] == 0)
     {
         buf[0]--;
     }
     i--;
 }

}*/
