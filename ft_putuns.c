/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:14:15 by msaidi            #+#    #+#             */
/*   Updated: 2022/11/25 17:23:54 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int n)
{
	unsigned long	nb;
	int				len;

	nb = n;
	len = 0;
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += write(1, &"0123456789"[nb % 10], 1);
	if (len < 0)
		return (-1);
	return (len);
}
