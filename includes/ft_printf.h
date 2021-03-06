/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 21:42:00 by kilkim            #+#    #+#             */
/*   Updated: 2020/04/17 21:42:01 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// FLAGS

# define F_SPACE 1
# define F_PLUS 2
# define F_MINUS 4
# define F_ZERO 8
# define F_HASH 16

// WIDTH & PRECISION

# define WIDTH 32
# define PRECI 64

// LENGTH_TYPE

# define LT_L 128
# define LT_LL 256
# define LT_BIGL 512
# define LT_H 1024
# define LT_HH 2048
# define LT_Z 4096

// CONVERSION_TYPE

# define CT_U 8192
# define CT_P 16384
# define CT_PERCENT 32768
# define CT_HEXUP 65536
# define CT_HEXDN 131072
# define CT_SIGN 262144

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct	s_dispatch_table
{
	char	specifier;
	void	(*ft)();
}				t_dt;

typedef struct	s_info
{
	va_list	ap;
	int		f;
	int		w;
	int		p;
	int		len;
}				t_info;

int				ft_printf(const char *s, ...);
int64_t			get_arg_type(t_info *info);
void			get_conversion(t_info *info, const char *s);
void			put_tok(char c, int len);
char			*max_itoa_base(uint64_t n, uint64_t base);
const char		*get_info(t_info *info, const char *s);

void			put_type_s(t_info *info);
void			put_type_c(t_info *info);
void			put_type_f(t_info *info);
void			put_type_di(t_info *info);
void			put_type_u(t_info *info);
void			put_type_xp(t_info *info);

#endif
