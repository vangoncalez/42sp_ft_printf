/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:56:10 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:13:01 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_decimal(int number, t_flags flags)
{
	flags = ft_pf_dec_b(number, flags);
	if (flags.f_zero == 0 && flags.f_minus == 0 && flags.p_dot > 0)
		flags = ft_pf_dec_d(number, flags);
	else if (flags.f_zero == 0 && flags.f_minus > 0 && flags.p_dot == 0)
		flags = ft_pf_dec_m(number, flags);
	else if (flags.f_zero == 0 && flags.f_minus > 0 && flags.p_dot > 0)
		flags = ft_pf_dec_md(number, flags);
	else if (flags.f_zero > 0 && flags.f_minus == 0 && flags.p_dot == 0)
		flags = ft_pf_dec_z(number, flags);
	else if (flags.f_zero > 0 && flags.f_minus == 0 && flags.p_dot > 0)
		flags = ft_pf_dec_zd(number, flags);
	flags = ft_pf_reinit_e(flags);
	return (flags);
}

t_flags	ft_pf_dec_b(int number, t_flags flags)
{
	int	i;

	i = 0;
	flags.tlen = ft_numberlen(number);
	if (flags.f_space > 0 && number >= 0)
	{
		put_flag(1, ' ');
		flags.tlen++;
	}
	if (flags.f_plus > 0 && number >= 0)
	{
		ft_putchar_fd('+', 1);
		flags.tlen++;
	}
	if (flags.f_zero == 0 && flags.f_minus == 0 && flags.p_dot == 0)
	{
		if (flags.w_number > 0)
			i = put_flag(flags.w_number_n - flags.tlen, ' ');
		ft_putnbr_fd(number, 1);
		flags.tlen = flags.tlen + i;
	}
	return (flags);
}

t_flags	ft_pf_nn(int number, int quant, int ftype, t_flags flags)
{
	int				i;
	long long int	lnumber;

	ft_putchar_fd('-', 1);
	i = put_flag(quant, ftype);
	lnumber = (long long int)number * -1;
	ft_putunbr_fd(lnumber, 1);
	flags.tlen = flags.tlen + i;
	return (flags);
}

t_flags	ft_pf_pn(int number, int quant, int ftype, t_flags flags)
{
	int	i;

	i = put_flag(quant, ftype);
	ft_putnbr_fd(number, 1);
	flags.tlen = flags.tlen + i;
	return (flags);
}

t_flags	ft_pf_sn(int number, t_flags flags)
{
	int	aux;

	aux = 0;
	if (flags.tlen <= flags.p_dot_n)
		aux = flags.p_dot_n - (flags.tlen - 1);
	flags.tlen += put_flag(flags.w_number_n - (flags.tlen + aux), ' ');
	ft_putchar_fd('-', 1);
	flags.tlen += put_flag(aux, '0');
	ft_putunbr_fd((long long int)number * -1, 1);
	return (flags);
}
