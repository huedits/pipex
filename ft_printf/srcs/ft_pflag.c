/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimatheu <vimatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:29:32 by vimatheu          #+#    #+#             */
/*   Updated: 2022/10/12 21:05:02 by vimatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

int	ft_pflag(unsigned long nbr)
{
	int	count;

	if (nbr == 0)
		count = ft_putstr(NULLTEXT);
	else
	{
		count = ft_putstr("0x");
		count += ft_printhex(nbr, 'x');
	}
	return (count);
}
