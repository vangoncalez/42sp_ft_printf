/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:51:21 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 11:59:25 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_pointer(unsigned long int number, t_flags flags)
{
	if (flags.w_number > 0 && flags.f_minus == 0)
		flags = ft_pf_poi_n(number, flags);
	if (flags.w_number == 0 && flags.f_minus == 0)
		flags = ft_pf_poi_none(number, flags);
	if (flags.w_number == 0 && flags.f_minus > 0)
		flags = ft_pf_poi_m(number, flags);
	flags = ft_pf_reinit_e(flags);
	return (flags);
}

t_flags	ft_pf_poi_b(unsigned long int number, t_flags flags, int aux)
{
	char	*str;

	ft_putstr_fd ("0x", 1);
	flags.tlen = ft_hexlen(number);
	str = (char *) malloc(sizeof(char) * (flags.tlen + 1));
	if (str)
	{
		ft_bzero(str, (flags.tlen + 1));
		if (!number)
			free(str);
		ft_putitohexlong(number, 0);
	}
	flags.tlen = 2 + ft_hexlen(number) + aux;
	ft_putstr_fd(str, 1);
	free(str);
	return (flags);
}

t_flags	ft_pf_poi_none(unsigned long int number, t_flags flags)
{
	if (number == 0)
	{
		ft_putstr_fd("0x0", 1);
		flags.tlen = 3;
		return (flags);
	}
	else
		flags = ft_pf_poi_b(number, flags, 0);
	return (flags);
}

void	ft_putitohexlong(unsigned long int num, int typec)
{
	char	c;

	if (num < 0)
		num *= -1;
	if (num >= 16)
	{
		ft_putitohexlong(num / 16, typec);
		ft_putitohexlong(num % 16, typec);
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
