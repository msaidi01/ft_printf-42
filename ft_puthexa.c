/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:13:02 by msaidi            #+#    #+#             */
/*   Updated: 2022/11/25 17:22:32 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char *base)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb > 16)
		len += ft_puthexa(nb / 16, base);
	len += write(1, &base[nb % 16], 1);
	if (len < 0)
		return (-1);
	return (len);
}
// int main()
// {
// 	printf("%d", ft_puthexa(-1, B16));
// }