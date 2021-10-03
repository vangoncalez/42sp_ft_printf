/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:12:59 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:13:48 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_str_md(char *str, t_flags flags)
{
	int	i;

	i = 0;
	flags.tlen = ft_strlen(str);
	if (flags.p_dot_n == -1)
		flags.p_dot_n = 0;
	while (i < flags.p_dot_n && str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (flags.f_minus_n > i)
		put_flag(flags.f_minus_n - i, ' ');
	flags.tlen = flags.f_minus_n;
	return (flags);
}

t_flags	ft_pf_str_m(char *str, t_flags flags)
{
	int	i;

	i = 0;
	flags.tlen = ft_strlen(str);
	ft_putstr_fd(str, 1);
	if (flags.f_minus_n > ft_strlen(str))
		i = put_flag(flags.f_minus_n - ft_strlen(str), ' ');
	flags.tlen = flags.tlen + i;
	return (flags);
}

t_flags	ft_pf_str_d(char *str, t_flags flags)
{
	int	i;

	i = 0;
	while (i < flags.p_dot_n && str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	flags.tlen = i;
	return (flags);
}

t_flags	ft_pf_str_n(char *str, t_flags flags)
{
	int	i;

	i = 0;
	flags.tlen = put_flag(flags.w_number_n - ft_strlen(str), ' ');
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	flags.tlen = flags.tlen + i;
	return (flags);
}

t_flags	ft_pf_str_b(char *str, t_flags flags)
{
	if (str)
		ft_putstr_fd(str, 1);
	flags.tlen = ft_strlen(str);
	if (flags.tlen == 0)
		flags.error = -1;
	return (flags);
}
