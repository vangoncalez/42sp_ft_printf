/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_undecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:20:42 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:13:31 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_undecimal(unsigned int number, t_flags flags)
{
	flags = ft_pf_undec_b(number, flags);
	if (flags.f_zero == 0 && flags.f_minus == 0 && flags.p_dot > 0)
		flags = ft_pf_undec_d(number, flags);
	else if (flags.f_zero == 0 && flags.f_minus > 0 && flags.p_dot == 0)
		flags = ft_pf_undec_m(number, flags);
	else if (flags.f_zero == 0 && flags.f_minus > 0 && flags.p_dot > 0)
		flags = ft_pf_undec_md(number, flags);
	else if (flags.f_zero > 0 && flags.f_minus == 0 && flags.p_dot == 0)
		flags = ft_pf_undec_z(number, flags);
	else if (flags.f_zero > 0 && flags.f_minus == 0 && flags.p_dot > 0)
		flags = ft_pf_undec_zd(number, flags);
	flags = ft_pf_reinit_e(flags);
	return (flags);
}

t_flags	ft_pf_undec_b(unsigned int number, t_flags flags)
{
	int	i;

	i = 0;
	if (number > 2147483647)
		flags.tlen = 10;
	else
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
		ft_putunbr_fd(number, 1);
		flags.tlen = flags.tlen + i;
	}
	return (flags);
}

t_flags	ft_pf_un(unsigned int number, int quant, int ftype, t_flags flags)
{
	int	i;

	i = put_flag(quant, ftype);
	ft_putunbr_fd(number, 1);
	flags.tlen = flags.tlen + i;
	return (flags);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n == 4294967295)
		write(fd, "4294967295", 10);
	else
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			c = '0' + n;
			ft_putchar_fd(c, fd);
		}
	}
}
