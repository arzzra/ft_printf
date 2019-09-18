
#ifndef LONG_MATH_DOUBLE_M_H
#define LONG_MATH_DOUBLE_M_H

//# include <unistd.h>
//# include <io.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string.h>

# define BASE 1000000000
# define BASELEN 9


typedef struct				s_qualfrs
{


    int					countchr;
    int					typs;
    int					width;
    int					prcs;
    void				*num;
    int					countnum;
    struct s_float		*ld;
    struct s_flag		*flg;
    struct s_length		*len;
    va_list				ap;
}							t_qualfrs;

typedef struct		s_float
{
    long long           sf_index;
    int                 iflg;//если intpart = 0 (первая цифра из fracpart)
    int                 fflg;//fmt->ld->fflg = 0;
	char                tmp;//
    unsigned			ovrld;
	int 				delta;
	short               carry;
	long long			totallen;
    long long           realprec;
    long long			count_0;
    long double         d;
    long long           e;
    long long           exp;
    short               sign_exp;

}					t_float;

typedef struct		s_flag
{
    int			sharp;
    int			zero;
    int			minus;
    int			plus;
    int			space;
}					t_flag;


typedef struct s_mantissa	t_parts;



typedef union
{
    long double d;
    struct
    {
        uint64_t mantissa : 64;
        uint64_t exponent : 15;
        uint64_t sign     : 1;
    } bits;
}u_ld;


typedef struct				s_div_coef
{
    uint64_t   n;
    uint64_t   m;
    uint64_t   scale;   // коэффициент нормализации
    uint64_t   qGuess;  // догадка для частного и соответствующий остаток
    uint64_t   temp1;
    uint64_t   r;

    long long       temp;
    long long       temp2;
    long long       carry; // переносы

    long            uJ;
    long            vJ;
    long            i;
    short           borrow;  // переносы
}							t_div_coef;



/*
 * * save_int_part_e.c
 */
char     *save_int_part_e(char *res_str, uint64_t *p_int, t_qualfrs *fmt);
long     fill_left_part(char *res_str, t_qualfrs *fmt);

/*
 * *solve_e.c
 */
char    *solve_e(uint64_t *p_int, uint64_t *p_frac, char **res_str, t_qualfrs *fmt);
uint64_t *cut_buf(uint64_t *buf, long long len);
char    *save_frac_part_e(char *sf, uint64_t *p_int, uint64_t *p_frac, t_qualfrs *fmt);
int     fill_right_part(char *res_str, t_qualfrs *fmt);
void    fill_e_end(char *s_full, t_qualfrs *fmt);

long long number_pow(long long num);

/*
 * *solve_f.c
 */
char        *solve_f(uint64_t *p_int, uint64_t *p_frac, char **res_str, t_qualfrs *fmt);
char		*save_int_part(char *res_str, uint64_t *buf, t_qualfrs *fmt);

void		zero_prec(char *s_full, uint64_t *buf, t_qualfrs *fmt);
void        put_first_simbol(char **p, t_qualfrs *fmt);


/*
 * *save_frac_part.c
 */
char		*save_frac_part(char *res_str, uint64_t *buf, t_qualfrs *fmt);
long long	get_buflen(uint64_t *buf);
void		fill_prec(char *s_full, uint64_t *buf, t_qualfrs *fmt);
void        round_line(char *s_full, t_qualfrs *fmt);

/*
 * *fill_res.c
 */
char 		*fill_res_f(char* res_str, char *s_full, t_qualfrs *fmt);
char 		*fill_res_e(char* res_str,  t_qualfrs *fmt);
//char 		*fill_res_i(char** res_str, char *s_full, t_qualfrs *fmt);

/*
 * long_operations.c
 */
//int     mod (unsigned long long *buf, unsigned dig,  unsigned long long *res);
uint64_t * mul_s(uint64_t *buf, unsigned dig);
uint64_t * add(uint64_t *buf1, uint64_t *buf2);
unsigned long   *add_s(unsigned long *buf,  unsigned  long dig);
uint64_t * div_s(uint64_t *buf, unsigned dig, uint64_t *res);

void    div_mod_s(uint64_t *buf_a, uint64_t b, uint64_t *res, uint64_t *rem);

unsigned long  *mul_l( unsigned long  *buf1,  unsigned long *buf2,  unsigned  long *res);
void			print_bits(size_t size, void *ptr, char space);
/*unsigned long long  get_mask( size_t pos, size_t n );
int                 bit_return_64(size_t a, int loc);*/


/*
 * div_mod_l.c
 */
void        div_mod_l(uint64_t *buf_a, uint64_t *buf_b, uint64_t *res);
int         simple_case_div_mod(uint64_t *buf_a, uint64_t *buf_b, uint64_t *res);
void        buf_normalize(uint64_t *scale, uint64_t *buf_a, uint64_t *buf_b);
void        guess_stabilization(uint64_t *r, uint64_t *qGuess, uint64_t nextpart, uint64_t *buf_b);
short       get_borrow(long long temp2, long vJ, unsigned i, uint64_t *buf_a);
long long   buf_b_cicle(t_div_coef *divcoef, uint64_t *buf_a, uint64_t *buf_b);
void        check_borrow(t_div_coef *divcoef, uint64_t *buf_a, uint64_t *buf_b, uint64_t *res);
void        get_zero_buf(uint64_t *buf, uint64_t m);
void        cicle_de_grandiozo(t_div_coef *divcoef, uint64_t *buf_a, uint64_t *buf_b, uint64_t *res);





/*
 * convert_mantiss.c
 */
void                replace_bit_max(void *src, char *int_part, char *frac_part, size_t size, long long exp );
void                replace_bit_min(void *src, char *frac_part, size_t size, long long exp);
char                *lead_zeros(long long exp, char *_part, char flag);
void                frac_to_str(void *src, char *frac_part, int i,int k, long long exp);

/*
 * print_int_part.c
 */
void            solve_int_part(char *s_int, char** res_str, t_qualfrs *fmt_feature);
uint64_t        *convert_integer(uint64_t *buf, char *s_int);
//void            get_buflen(long long   *len,unsigned long  *buf);
void            check_len_fmt(long long   *count, t_qualfrs *fmt);


/*
 * print_frac_part_v2.c
 */
//void                    convert_fraction(unsigned long  *buf, char *s_part, unsigned long  base, unsigned baselen);

unsigned long      max_len_pow_5(unsigned long long *buf_5n, unsigned long  base,  unsigned baselen);
unsigned                start_index(char *s_part);
void                    keep_fraction(char *s_part, unsigned start_i,unsigned long  *buf_5n, unsigned  long base, unsigned baselen);
unsigned                maxpow_five(char *s_frac);

/*
 * print_frac_part.c
 */
void                pow_of_num(uint64_t *buf_n, uint64_t  exp, unsigned num);
void                print_last_zero(int prec);
void                copy_buf_ull(const uint64_t *src, uint64_t *dst);
uint64_t            *convert_fraction(char *s_frac, uint64_t *buf,  t_qualfrs *fmt_feature);
void                keep_mod(unsigned long *buf, unsigned long base, unsigned baselen, long long exp);
void                div_mod(unsigned long *buf, unsigned long *res, unsigned  long base, unsigned baselen, long long exp);
void                convert_string(uint64_t *buf, char *s_part);


/*
** buffer.c
*/
unsigned long  *init_buf(unsigned long long_num, unsigned  long base, unsigned buflen);
unsigned            ret_buflen(unsigned long long_num, unsigned  long base);
void                print_buf(unsigned long *buf, unsigned count_0, char c, t_qualfrs *fmt_feature);
void                buf_to_str(uint64_t *buf, char *s_full);

//void                fill_int_str(unsigned long long *buf, t_qualfrs *f);
//void                put_right_int(char *p_start, t_qualfrs *f);
//void                put_left_int(char *p_start, t_qualfrs *f);

//void                fill_frac_str(unsigned count_0, unsigned long long *buf, t_qualfrs *fmt_feature);





/*
** main.c
*/

void                divide_and_conquer(u_ld *un, t_qualfrs *fmt);
char                *ft_itoa_base_ll(uint64_t dig, int radix);
void                pow_of_two(uint64_t *buf_2n, unsigned long exp);
uint64_t count_zero_after_point(long double d);
void conver_parts(char *s_int, char *s_frac, t_qualfrs *fmt);

#endif
