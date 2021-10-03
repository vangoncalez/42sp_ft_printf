/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:56:06 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:47:57 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_char(int c, t_flags flags)
{
	flags.tlen = 0;
	if (flags.w_number > 0)
	{
		put_flag(flags.w_number_n - 1, ' ');
		flags.tlen = flags.w_number_n - 1;
		flags.w_number = 0;
	}
	ft_putchar_fd(c, 1);
	if (flags.f_minus > 0)
	{
		put_flag(flags.f_minus_n - 1, ' ');
		if (flags.f_minus_n > 0)
			flags.tlen = flags.f_minus_n - 1;
		flags.f_minus = 0;
	}
	flags.tlen = flags.tlen + 1;
	return (flags);
}

t_flags	ft_pf_string(char *str, t_flags flags)
{
	flags.tlen = 0;
	if (str == NULL)
		flags = ft_pf_str_p("(null)", flags);
	else
		flags = ft_pf_str_p(str, flags);
	return (flags);
}

t_flags	ft_pf_str_p(char *str, t_flags flags)
{
	flags.tlen = 0;
	if (flags.f_minus > 0 && flags.p_dot > 0 && flags.w_number == 0)
	{
		if (flags.p_dot_n == 0 && flags.f_minus_n == 0)
		{
			flags.error = -1;
			return (flags);
		}
		flags = ft_pf_str_md(str, flags);
	}
	else if (flags.f_minus > 0 && flags.p_dot == 0 && flags.w_number == 0)
		flags = ft_pf_str_m(str, flags);
	else if (flags.f_minus == 0 && flags.p_dot > 0 && flags.w_number == 0)
		flags = ft_pf_str_d(str, flags);
	else if (flags.f_minus == 0 && flags.p_dot == 0 && flags.w_number > 0)
		flags = ft_pf_str_n(str, flags);
	else
		flags = ft_pf_str_b(str, flags);
	flags = ft_pf_reinit_e (flags);
	return (flags);
}
