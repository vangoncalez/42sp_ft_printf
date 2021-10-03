/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:55:23 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:14:29 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_hex_d(int number, t_flags flags, int tcase)
{
	int	aux;

	aux = 0;
	if (number < 0)
		flags.tlen = 8;
	else
		flags.tlen = ft_hexlen(number);
	if (flags.tlen < flags.p_dot_n)
		aux = flags.p_dot_n - flags.tlen;
	flags.tlen += put_flag(flags.w_number_n - (flags.tlen + aux), ' ');
	flags.tlen += put_flag(aux, '0');
	if (flags.p_dot_n == 0 && number == 0)
	{
		flags.tlen = 0;
		flags.error = -1;
	}
	else
		ft_putitohex(number, tcase);
	return (flags);
}

t_flags	ft_pf_hex_m(int number, t_flags flags, int tcase)
{
	if (number < 0)
		flags.tlen = 8;
	else
		flags.tlen = ft_hexlen(number);
	ft_putitohex(number, tcase);
	if (flags.tlen < flags.f_minus_n)
		flags.tlen += put_flag(flags.f_minus_n - flags.tlen, ' ');
	return (flags);
}

t_flags	ft_pf_hex_md(int number, t_flags flags, int tcase)
{
	if (number < 0)
		flags.tlen = 8;
	else
		flags.tlen = ft_hexlen(number);
	if (flags.tlen < flags.p_dot_n)
		flags.tlen += put_flag(flags.p_dot_n - flags.tlen, '0');
	if (flags.p_dot_n == 0 && number == 0)
		flags.tlen = 0;
	else
		ft_putitohex(number, tcase);
	if (flags.tlen < flags.f_minus_n)
		flags.tlen += put_flag(flags.f_minus_n - flags.tlen, ' ');
	return (flags);
}

t_flags	ft_pf_hex_z(int number, t_flags flags, int tcase)
{
	if (number < 0)
		flags.tlen = 8;
	else
		flags.tlen = ft_hexlen(number);
	if (flags.tlen < flags.w_number_n)
		flags.tlen += put_flag(flags.w_number_n - flags.tlen, '0');
	if (flags.w_number_n == 0 && number == 0)
	{
		flags.tlen = 0;
		flags.error = -1;
	}
	else
		ft_putitohex(number, tcase);
	return (flags);
}

t_flags	ft_pf_hex_zd(int number, t_flags flags, int tcase)
{
	int	aux;

	aux = 0;
	if (number < 0)
		flags.tlen = 8;
	else
		flags.tlen = ft_hexlen(number);
	if (number == 0)
	{
		flags.tlen = put_flag(flags.w_number_n - flags.p_dot_n, ' ');
		flags.tlen += put_flag(flags.p_dot_n, '0');
	}
	else
	{
		if (flags.tlen < flags.p_dot_n)
			aux = flags.p_dot_n - flags.tlen;
		flags.tlen += put_flag(flags.w_number_n - (flags.tlen + aux), ' ');
		flags.tlen += put_flag(aux, '0');
		if (flags.p_dot_n == 0 && number == 0)
			flags.tlen = flags.w_number_n;
		else
			ft_putitohex(number, tcase);
	}
	return (flags);
}
