#include "double_m.h"



/*void    print_int_part(char *s_int, unsigned long long base, unsigned baselen)
{
    unsigned long long buf[1001];

    convert_integer(buf, s_int, base, baselen);
    for(int i = 0; i <= buf[0]; i++)
    {
        printf("_%llu", buf[i]);

    }
    printf("\n");
    print_buf(buf, 18,0);

}*/

/*void convert_integer(unsigned long long *buf, char *s_int, unsigned long long base, unsigned baselen)
{
    unsigned maxpow;
    unsigned i;
    unsigned long long buf_2n[1001];

    buf[0] = 1;
    buf[1] = 0;
    i = 0;
    maxpow = ft_strlen(s_int) - 1;
    while(s_int[maxpow - i] == '0')//пропустить младшие "0"
    {
         i++;
    }
    pow_of_two(buf_2n, i, base, baselen);//сохраняю начальную степень 2
    while(i < maxpow)
    {
        if (i == 0)
            buf[1] = 1;
        mul_s(buf_2n, 2, base);
        if (s_int[maxpow - i - 1] == '1')
        {
            add(buf, buf_2n, base);
        }
        i++;
    }


}*/

/*void pow_of_two( unsigned long long *buf_2n, unsigned long long exp, unsigned long long base, unsigned  baselen)
{
    buf_2n[0] = 1;
    buf_2n[1] = 1;

    while (exp > 0)
    {
        mul_s(buf_2n, 2, base);
        exp--;
    }
    printf("buf_2n[0] = %llu\n", buf_2n[0]);
    //return(buf_2n);
}*/
