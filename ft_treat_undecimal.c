/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_undecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:44:54 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 11:50:51 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_undec_d(unsigned int number, t_flags flags)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	if (flags.tlen > flags.p_dot_n && number != 0)
		ft_putunbr_fd(number, 1);
	else
	{
		if (number == 0 && flags.p_dot_n == 0)
		{
			flags.tlen = 0;
			flags.error = -1;
		}
		else
		{
			i = put_flag(flags.p_dot_n - flags.tlen, '0');
			ft_putunbr_fd(number, 1);
			flags.tlen = flags.tlen + i;
		}
	}
	return (flags);
}

t_flags	ft_pf_undec_m(unsigned int number, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.f_minus_n == 0)
	{
		ft_putunbr_fd(number, 1);
		if (number > 2147483647)
			flags.tlen = 10;
		else
			flags.tlen = ft_numberlen(number);
	}
	else if (flags.f_minus_n > 0)
	{
		ft_putunbr_fd(number, 1);
		i = put_flag(flags.f_minus_n - flags.tlen, ' ');
		flags.tlen = flags.tlen + i;
	}
	return (flags);
}

t_flags	ft_pf_undec_md(unsigned int number, t_flags flags)
{
	if (number == 0)
	{
		flags.tlen = 0;
		if (flags.p_dot_n != 0)
			flags.tlen = put_flag(flags.p_dot_n, '0');
		flags.tlen += put_flag(flags.f_minus_n - flags.tlen, ' ');
	}
	else
	{
		flags = ft_pf_un(number, flags.p_dot_n - flags.tlen, '0', flags);
		if (flags.tlen < flags.f_minus_n)
			flags.tlen += put_flag(flags.f_minus_n - flags.tlen, ' ');
	}
	return (flags);
}

t_flags	ft_pf_undec_z(unsigned int number, t_flags flags)
{
	if (flags.tlen > flags.w_number_n && number != 0)
		ft_putunbr_fd(number, 1);
	else
	{
		if (number == 0 && flags.w_number_n == 0)
		{
			flags.tlen = 0;
			flags.error = -1;
		}
		else
			flags = ft_pf_un(number, flags.w_number_n - flags.tlen, '0', flags);
	}
	return (flags);
}

t_flags	ft_pf_undec_zd(unsigned int number, t_flags flags)
{
	int	aux;

	aux = 0;
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
		ft_putunbr_fd(number, 1);
	}
	return (flags);
}
