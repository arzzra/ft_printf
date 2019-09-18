#include "double_m.h"



/*void convert_fraction(unsigned long long *buf, char *s_part, unsigned long long base, unsigned baselen)
{
    unsigned            maxpow;
    unsigned long long  buf_5n[1001];

    unsigned            start_i; // пропустить нули в начале строки(для дробной части)

    buf[0] = 1;
    buf[1] = 0;

    start_i = start_index(s_part); // пропустить нули в начале строки(для дробной части)
    keep_fraction(s_part, start_i, buf_5n, base, baselen);



}



void    keep_fraction(char *s_part, unsigned start_pow,unsigned long long *buf_5n, unsigned long long base, unsigned baselen)
{
    unsigned            maxpow;
    unsigned long long  buf_10n[1001];
    unsigned long long  tmp[1001];
    unsigned long long  res[1001];

    maxpow = maxpow_five(s_part);//определить макимальную степень 5
    pow_of_num(res, maxpow, 5);// возвести 5 в эту степень и сохранить в res
    printf("\nres_start(5^%u):\n", maxpow);
    for (unsigned n = res[0]; n >= 1; n--)
    {
        printf("_%llu_",res[n]);
    }

    pow_of_num(buf_5n, start_pow, 5);// возвести 5 в начальную степень
    printf("\nstart_5_pow(5^%u):\n", start_pow);
    for (unsigned n = buf_5n[0]; n >= 1; n--)
    {
        printf("_%llu_",buf_5n[n]);
    }
    pow_of_num(buf_10n, maxpow - start_pow, 10);// возвести 10 в начальную степень
    printf("\nstart_10_pow(10^%u):\n", maxpow - start_pow);
    for (unsigned n = buf_10n[0]; n >= 1; n--)
    {
        printf("_%llu_",buf_10n[n]);
    }
    while (start_pow <= maxpow-1)
    {
        if (s_part[start_pow - 1] == '1')
        {
            if(buf_5n[0] > buf_10n[0])
                mul_l(buf_5n, buf_10n, tmp);
            else
                mul_l(buf_10n, buf_5n, tmp);
            printf("\ntmp_after_mul_l:\n");
            for (unsigned n = tmp[0]; n >= 1; n--)
            {
                printf("_%llu_",tmp[n]);
            }
            printf("\n");
            add(res, tmp);
            printf("\nres_after_add:\n");
            for (unsigned n = res[0]; n >= 1; n--)
            {
                printf("_%llu_",res[n]);
            }
            printf("\n");
        }
        mul_s(buf_5n, 5);
        div_s(buf_10n, 10, tmp);
        printf("end_start_pow_%u_\n",start_pow);
        start_pow++;
    }
    printf("\nres_after_all:\n");
    for (unsigned n = res[0]; n >= 1; n--)
    {
        printf("_%llu_",res[n]);
    }
}


unsigned maxpow_five(char *s_frac)
{
    unsigned            maxpow;
    unsigned            i;

    i = 0;
    maxpow = ft_strlen(s_frac) - 1;

    while(s_frac[maxpow - i] == '0')//пропустить "0" в конце строки
    {
        i++;
    }
    printf("maxpow_five = %u\n", maxpow - i + 1);
    return (maxpow - i + 1);
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
}*/

/*unsigned long long   max_len_pow_5(unsigned long long *buf_5n, unsigned long long base,  unsigned baselen)
{
    unsigned long long max_len_pow_5;
    unsigned long long last_elem;

    max_len_pow_5 = baselen * (buf_5n[0] - 1);
    last_elem = buf_5n[buf_5n[0]];
    while(last_elem != 0)
    {
        last_elem /= 10;
        max_len_pow_5++;
    }
    printf("max_len_pow_5 = %llu\n", max_len_pow_5);
    return (max_len_pow_5);

}*/

