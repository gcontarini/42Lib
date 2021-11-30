/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcontari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:35:05 by gcontari          #+#    #+#             */
/*   Updated: 2021/11/26 11:03:30 by gcontari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include "libft.h"
# define STDOUT_FD 1
# define NO_UPHEX 1
# define NO_DIG 2
# define NO_INT 3
# define NO_UINT 4
# define NO_LOWHEX 5
# define NO_PERC 6
# define NO_PTRADDR 7
# define NO_CHAR 8
# define NO_STR 9
# define NO_NUM 10		// Width (right)
# define NO_DOT 11		// Precision (right with zeros)
# define NO_MINUS 12	// Width (left)
# define NO_ZERO 13		// Width (left with zeros)
# define NO_HASH 14		// Adds 0x to hex numbers
# define NO_SPACE 15 	// Adds space or neg sign
# define NO_PLUS 16 	// Adds plus or minus sign
# define PH 10			// Total place holders
# define TOTOP 7		// Total options available
# define INVLD_PHLR -1

typedef struct s_queue_unit
{
	int					len;
	int					type;
	int					op[TOTOP];
	struct s_queue_unit	*last;
}	t_qunit;

typedef struct s_queue
{
	t_qunit				*head;
	t_qunit				*tail;
}	t_queue;

typedef struct s_result_place_holder
{
	int					len;
	int					type;
	int					op[TOTOP];
}	t_argholder;

typedef struct s_flag_options
{
	int					len;
	int					width;
	int					dot;
	int					minus;
	int					zero;
	int					space;
	int					plus;
	int					hash;
}	t_flagop;

// ft_printf
int			ft_printf(const char *str, ...);
int			ft_vprintf(const char *str, va_list ap);

// ftpft_queue
t_queue		*start_queue(void);
t_queue		*add_queue(t_queue *queue, t_argholder op);
t_qunit		pool_queue(t_queue *queue);
void		clean_queue(t_queue *queue);

// ftpft_memerror
int			memerror_int(void);
t_queue		*memerror_queue(t_queue *queue);

// ftpft_jptab
void		fill_table(char table[256]);
void		fill_fptable(int (*fptable[PH])(t_qunit, va_list));
void		fill_re_options(t_argholder *re);

// ftpft_args
int			check_args(t_queue *queue);
t_queue		*parse_args(const char *str, char table[256]);
t_argholder	flag_type(const char *str, char table[256]);
int			parse_optn(const char *str, t_argholder *re);
int			parse_opt(const char *str, t_argholder *re);

// ftpft_flush
int			flush_str(const char **str);
int			flush_var(const char **s, t_queue *q, va_list ap, int (**ptable)());
char		*take_op_sign(char *p, t_qunit qu, int n);

// ftptf_int
int			write_int(t_qunit qu, va_list ap);
char		*buff_int_width(t_qunit qu, int n);
char		*buff_int_minus(t_qunit qu, int n);
char		*buff_int_zero(t_qunit qu, int n);
char		*buff_int_dot(t_qunit qu, int n);

// ftptf_uint
int			write_uint(t_qunit qu, va_list ap);
char		*buff_uint_width(t_qunit qu, unsigned int n);
char		*buff_uint_minus(t_qunit qu, unsigned int n);
char		*buff_uint_zero(t_qunit qu, unsigned int n);
char		*buff_uint_dot(t_qunit qu, unsigned int n);

// ftptf_lowhex
int			write_lowhex(t_qunit qu, va_list ap);
char		*buff_lowhex_width(t_qunit qu, unsigned int n);
char		*buff_lowhex_minus(t_qunit qu, unsigned int n);
char		*buff_lowhex_zero(t_qunit qu, unsigned int n);
char		*buff_lowhex_dot(t_qunit qu, unsigned int n);

// ftptf_uphex
int			write_uphex(t_qunit qu, va_list ap);
char		*buff_uphex_width(t_qunit qu, unsigned int n);
char		*buff_uphex_minus(t_qunit qu, unsigned int n);
char		*buff_uphex_zero(t_qunit qu, unsigned int n);
char		*buff_uphex_dot(t_qunit qu, unsigned int n);

// ftptf_char
int			write_char(t_qunit qunit, va_list ap);
char		*buff_char_width(t_qunit qu, unsigned char c);
char		*buff_char_minus(t_qunit qu, unsigned char c);

// ftptf_str
int			write_str(t_qunit qunit, va_list ap);
char		*buff_str_width(t_qunit qu, char *str);
char		*buff_str_minus(t_qunit qu, char *str);
char		*buff_str_dot(t_qunit qu, char *str);

// ftptf_perc
int			write_percent(t_qunit qunit);
char		*buff_perc_width(t_qunit qu);
char		*buff_perc_minus(t_qunit qu);
char		*buff_perc_zero(t_qunit qu);

// ftptf_ptr
int			write_ptraddr(t_qunit qunit, va_list ap);
char		*buff_ptr_width(t_qunit qu, unsigned long ptr);
char		*buff_ptr_minus(t_qunit qu, unsigned long ptr);
char		*buff_ptr(unsigned long ptr);

#endif
