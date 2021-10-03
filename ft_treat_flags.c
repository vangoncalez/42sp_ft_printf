/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:38:38 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:12:17 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_flag(int quant, int ftype)
{
	int	i;

	i = 0;
	while (i < quant)
	{
		ft_putchar_fd(ftype, 1);
		i++;
	}
	return (i);
}

t_flags	ft_pf_reinit_c(t_flags flags)
{
	flags.w_number = 0;
	flags.f_zero = 0;
	flags.f_hash = 0;
	flags.f_minus = 0;
	flags.f_space = 0;
	flags.f_plus = 0;
	flags.p_dot = 0;
	flags.error = 0;
	flags.w_number_n = 0;
	flags.f_minus_n = 0;
	flags.p_dot_n = 0;
	flags.control = 1;
	return (flags);
}

t_flags	ft_pf_reinit_e(t_flags flags)
{
	flags.w_number = 0;
	flags.f_zero = 0;
	flags.f_hash = 0;
	flags.f_minus = 0;
	flags.f_space = 0;
	flags.f_plus = 0;
	flags.p_dot = 0;
	flags.w_number_n = 0;
	flags.f_minus_n = 0;
	flags.p_dot_n = 0;
	return (flags);
}

t_flags	ft_pf_init(void)
{
	t_flags		flags;

	flags.w_number = 0;
	flags.f_zero = 0;
	flags.f_hash = 0;
	flags.f_minus = 0;
	flags.f_space = 0;
	flags.f_plus = 0;
	flags.p_dot = 0;
	flags.error = 0;
	flags.len = 0;
	flags.plen = 0;
	flags.nlen = 0;
	flags.tlen = 0;
	flags.w_number_n = 0;
	flags.f_minus_n = 0;
	flags.p_dot_n = 0;
	flags.control = 0;
	return (flags);
}
