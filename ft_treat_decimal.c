/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 09:43:46 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:12:06 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_dec_d(int number, t_flags flags)
{
	int	aux;

	aux = 0;
	if (flags.tlen > flags.p_dot_n && number != 0)
		ft_putnbr_fd(number, 1);
	else
	{
		if (number == 0 && flags.p_dot_n == 0)
		{
			flags.tlen = 0;
			flags.error = -1;
		}
		else if (number >= 0)
		{
			if (flags.tlen < flags.p_dot_n)
				aux = flags.p_dot_n - flags.tlen;
			flags.tlen += put_flag(flags.w_number_n - (flags.tlen + aux), ' ');
			flags.tlen += put_flag(aux, '0');
			ft_putnbr_fd(number, 1);
		}
		else if (number < 0)
			flags = ft_pf_sn(number, flags);
	}
	return (flags);
}

t_flags	ft_pf_dec_m(int number, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.f_minus_n == 0)
	{
		ft_putnbr_fd(number, 1);
		flags.tlen = ft_numberlen(number);
	}
	else if (flags.f_minus_n > 0)
	{
		ft_putnbr_fd(number, 1);
		i = put_flag(flags.f_minus_n - flags.tlen, ' ');
		flags.tlen = flags.tlen + i;
	}
	return (flags);
}

t_flags	ft_pf_dec_md(int number, t_flags flags)
{
	if (number > 0)
	{
		flags = ft_pf_pn(number, flags.p_dot_n - flags.tlen, '0', flags);
		if (flags.tlen < flags.f_minus_n)
			flags.tlen += put_flag(flags.f_minus_n - flags.tlen, ' ');
	}
	else if (number < 0)
	{
		flags = ft_pf_nn(number, flags.p_dot_n - flags.tlen + 1, '0', flags);
		if (flags.tlen < flags.f_minus_n)
			flags.tlen += put_flag(flags.f_minus_n - flags.tlen, ' ');
	}
	else
	{
		flags.tlen = 0;
		if (flags.p_dot_n != 0)
			flags.tlen = put_flag(flags.p_dot_n, '0');
		flags.tlen += put_flag(flags.f_minus_n - flags.tlen, ' ');
	}
	return (flags);
}

t_flags	ft_pf_dec_z(int number, t_flags flags)
{
	if (flags.tlen > flags.w_number_n && number != 0)
		ft_putnbr_fd(number, 1);
	else
	{
		if (number == 0 && flags.w_number_n == 0)
		{
			flags.tlen = 0;
			flags.error = -1;
		}
		else if (number >= 0)
			flags = ft_pf_pn(number, flags.w_number_n - flags.tlen, '0', flags);
		else if (number < 0)
			flags = ft_pf_nn(number, flags.w_number_n - flags.tlen, '0', flags);
	}
	return (flags);
}

t_flags	ft_pf_dec_zd(int number, t_flags flags)
{
	int	aux;

	aux = 0;
	if (number > 0)
	{
		if (flags.tlen < flags.p_dot_n)
			aux = flags.p_dot_n - flags.tlen;
		flags.tlen += put_flag(flags.w_number_n - (flags.tlen + aux), ' ');
		flags.tlen += put_flag(aux, '0');
		ft_putnbr_fd(number, 1);
	}
	else if (number < 0)
		flags = ft_pf_sn(number, flags);
	else
	{
		flags.tlen = put_flag(flags.w_number_n - flags.p_dot_n, ' ');
		flags.tlen += put_flag(flags.p_dot_n, '0');
	}
	return (flags);
}
