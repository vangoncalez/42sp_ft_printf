/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:56:14 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:13:10 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_hexa(int number, t_flags flags, int tcase)
{
	flags = ft_pf_hex_b(number, flags, tcase);
	if (flags.f_zero == 0 && flags.f_minus == 0 && flags.p_dot > 0)
		flags = ft_pf_hex_d(number, flags, tcase);
	else if (flags.f_zero == 0 && flags.f_minus > 0 && flags.p_dot == 0)
		flags = ft_pf_hex_m(number, flags, tcase);
	else if (flags.f_zero == 0 && flags.f_minus > 0 && flags.p_dot > 0)
		flags = ft_pf_hex_md(number, flags, tcase);
	else if (flags.f_zero > 0 && flags.f_minus == 0 && flags.p_dot == 0)
		flags = ft_pf_hex_z(number, flags, tcase);
	else if (flags.f_zero > 0 && flags.f_minus == 0 && flags.p_dot > 0)
		flags = ft_pf_hex_zd(number, flags, tcase);
	if (flags.f_hash > 0 && number != 0)
		flags.tlen += 2;
	flags = ft_pf_reinit_e(flags);
	return (flags);
}

t_flags	ft_pf_hex_b(int number, t_flags flags, int tcase)
{
	if (flags.f_hash > 0 && number != 0)
	{
		ft_putchar_fd('0', 1);
		if (tcase == 0)
			ft_putchar_fd('x', 1);
		else
			ft_putchar_fd('X', 1);
	}
	if (flags.f_zero == 0 && flags.f_minus == 0 && flags.p_dot == 0)
	{
		if (number < 0)
			flags.tlen = 8;
		else
			flags.tlen = ft_hexlen(number);
		if (flags.w_number > 0)
			flags.tlen += put_flag(flags.w_number_n - flags.tlen, ' ');
		ft_putitohex(number, tcase);
	}
	return (flags);
}

void	ft_putitohex(unsigned int num, int typec)
{
	char	c;

	if (num < 0)
	{
		num *= -1;
	}
	if (num >= 16)
	{
		ft_putitohex(num / 16, typec);
		ft_putitohex(num % 16, typec);
	}
	else
	{
		if (num < 10)
			c = '0' + num;
		else
		{
			if (typec == 0)
				c = 87 + num;
			else
				c = 55 + num;
		}
		write(1, &c, 1);
	}
}
