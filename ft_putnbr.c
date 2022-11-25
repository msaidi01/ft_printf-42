/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:14:55 by msaidi            #+#    #+#             */
/*   Updated: 2022/11/25 17:24:07 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long int	nb;
	int			len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb *= -1;
	len += write(1, "-", 1);
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += write(1, &"0123456789"[nb % 10], 1);
	if (len < 0)
		return (-1);
	return (len);
}
