/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:03:45 by vaferrei          #+#    #+#             */
/*   Updated: 2021/10/03 12:14:36 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_pf_poi_n(unsigned long int number, t_flags flags)
{
	int		aux;

	aux = 0;
	if (number == 0)
		aux = 3;
	else
		aux = ft_hexlen(number) + 2;
	aux = put_flag(flags.w_number_n - aux, ' ');
	if (number == 0)
	{
		ft_putstr_fd("0x0", 1);
		flags.tlen = 3 + aux;
	}
	else
		flags = ft_pf_poi_b(number, flags, aux);
	return (flags);
}

t_flags	ft_pf_poi_m(unsigned long int number, t_flags flags)
{
	if (number == 0)
	{
		ft_putstr_fd("0x0", 1);
		flags.tlen = 3;
	}
	else
		flags = ft_pf_poi_b(number, flags, 0);
	flags.tlen += put_flag(flags.f_minus_n - flags.tlen, ' ');
	return (flags);
}
