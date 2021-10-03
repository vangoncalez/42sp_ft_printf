/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:56:26 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:00:48 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_pf_check(char ch, va_list args, t_flags flags);
static t_flags	ft_pf_save_flags(char ch, t_flags flags);
static t_flags	ft_pf_isdigit(char ch, t_flags flags);
static t_flags	ft_pf_minus(t_flags flags);

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_flags		flags;
	int			i;

	va_start(args, str);
	i = 0;
	flags = ft_pf_init();
	while (str[i] != '\0')
	{
		flags.plen = flags.len;
		if (flags.error == -1)
			flags.control = 0;
		if ((str[i] == '%') && (flags.control == 0))
			flags = ft_pf_reinit_c(flags);
		else
		{
			flags = ft_pf_check(str[i], args, flags);
			flags.len = flags.plen + flags.tlen;
			if ((flags.plen < flags.len))
				flags.control = 0;
		}
		i++;
	}
	va_end(args);
	return (flags.len);
}

static t_flags	ft_pf_check(char ch, va_list args, t_flags flags)
{
	if (flags.control == 0)
		flags = ft_pf_char(ch, flags);
	else if (ch == 'c')
		flags = ft_pf_char(va_arg(args, int), flags);
	else if (ch == 's')
		flags = ft_pf_string(va_arg(args, char *), flags);
	else if (ch == 'p')
		flags = ft_pf_pointer(va_arg(args, unsigned long int), flags);
	else if (ch == 'd' || ch == 'i')
		flags = ft_pf_decimal(va_arg(args, int), flags);
	else if (ch == 'u')
		flags = ft_pf_undecimal(va_arg(args, unsigned int), flags);
	else if (ch == 'x')
		flags = ft_pf_hexa(va_arg(args, int), flags, 0);
	else if (ch == 'X')
		flags = ft_pf_hexa(va_arg(args, int), flags, 1);
	else if (ch == '%')
		flags = ft_pf_char('%', flags);
	else
		flags = ft_pf_save_flags(ch, flags);
	return (flags);
}

static t_flags	ft_pf_save_flags(char ch, t_flags flags)
{
	if (ft_isdigit(ch))
		flags = ft_pf_isdigit(ch, flags);
	else if (ch == '-')
		flags = ft_pf_minus(flags);
	else if (ch == '.')
	{
		flags.p_dot = 2;
		if (flags.w_number == 2)
			flags.w_number = 1;
		if (flags.f_minus == 2)
			flags.f_minus = 1;
	}
	else if (ch == '#')
		flags.f_hash = 1;
	else if (ch == ' ')
		flags.f_space = 1;
	else if (ch == '+')
		flags.f_plus = 1;
	flags.tlen = 0;
	return (flags);
}

static t_flags	ft_pf_isdigit(char ch, t_flags flags)
{
	if (ch == 48)
	{
		if (flags.w_number == 0 && flags.f_minus == 0 && flags.p_dot == 0)
		{
			flags.f_zero = 1;
			return (flags);
		}
	}
	if (flags.f_minus != 2 && flags.p_dot != 2)
	{
		flags.w_number_n = (flags.w_number_n * 10) + (ch - 48);
		flags.w_number = 1;
	}
	else if (flags.f_minus == 2)
		flags.f_minus_n = (flags.f_minus_n * 10) + (ch - 48);
	else if (flags.p_dot == 2)
		flags.p_dot_n = (flags.p_dot_n * 10) + (ch - 48);
	return (flags);
}

static t_flags	ft_pf_minus(t_flags flags)
{
	flags.f_minus = 2;
	if (flags.w_number == 2)
		flags.w_number = 1;
	if (flags.p_dot == 2)
		flags.p_dot = 1;
	return (flags);
}
