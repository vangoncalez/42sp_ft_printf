/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:50:58 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:18:43 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	w_number;
	int	f_minus;
	int	p_dot;
	int	w_number_n;
	int	f_minus_n;
	int	p_dot_n;
	int	f_zero;
	int	f_hash;
	int	f_space;
	int	f_plus;
	int	error;
	int	control;
	int	len;
	int	plen;
	int	nlen;
	int	tlen;
}	t_flags;

int		ft_printf(const char *str, ...);
t_flags	ft_pf_char(int c, t_flags flags);
t_flags	ft_pf_string(char *str, t_flags flags);
t_flags	ft_pf_str_p(char *str, t_flags flags);
t_flags	ft_pf_str_md(char *str, t_flags flags);
t_flags	ft_pf_str_m(char *str, t_flags flags);
t_flags	ft_pf_str_d(char *str, t_flags flags);
t_flags	ft_pf_str_n(char *str, t_flags flags);
t_flags	ft_pf_str_b(char *str, t_flags flags);
t_flags	ft_pf_decimal(int number, t_flags flags);
t_flags	ft_pf_dec_b(int number, t_flags flags);
t_flags	ft_pf_nn(int number, int quant, int ftype, t_flags flags);
t_flags	ft_pf_pn(int number, int quant, int ftype, t_flags flags);
t_flags	ft_pf_sn(int number, t_flags flags);
t_flags	ft_pf_dec_d(int number, t_flags flags);
t_flags	ft_pf_dec_m(int number, t_flags flags);
t_flags	ft_pf_dec_md(int number, t_flags flags);
t_flags	ft_pf_dec_z(int number, t_flags flags);
t_flags	ft_pf_dec_zd(int number, t_flags flags);
t_flags	ft_pf_undecimal(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_b(unsigned int number, t_flags flags);
t_flags	ft_pf_un(unsigned int number, int quant, int ftype, t_flags flags);
void	ft_putunbr_fd(unsigned int n, int fd);
t_flags	ft_pf_undec_d(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_m(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_md(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_z(unsigned int number, t_flags flags);
t_flags	ft_pf_undec_zd(unsigned int number, t_flags flags);
t_flags	ft_pf_hexa(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_b(int number, t_flags flags, int tcase);
void	ft_putitohex(unsigned int num, int typec);
t_flags	ft_pf_hex_d(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_m(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_md(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_z(int number, t_flags flags, int tcase);
t_flags	ft_pf_hex_zd(int number, t_flags flags, int tcase);
t_flags	ft_pf_pointer(unsigned long int number, t_flags flags);
t_flags	ft_pf_poi_b(unsigned long int number, t_flags flags, int aux);
t_flags	ft_pf_poi_none(unsigned long int number, t_flags flags);
void	ft_putitohexlong(unsigned long int num, int typec);
t_flags	ft_pf_poi_n(unsigned long int number, t_flags flags);
t_flags	ft_pf_poi_m(unsigned long int number, t_flags flags);
int		put_flag(int quant, int ftype);
t_flags	ft_pf_init(void);
t_flags	ft_pf_reinit_e(t_flags flags);
t_flags	ft_pf_reinit_c(t_flags flags);

#endif
