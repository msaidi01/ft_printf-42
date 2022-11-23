#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	int r;

	r = write(1, &c, 1);
	if (r < 0)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	r;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(s);
	r = write(1, s, i);
	if (r < 0)
		return (-1);
	return(i);
}

void	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb > 9)
	ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

void	ft_putuns(unsigned int n)
{
	unsigned	long nb;

	nb = n;
	if (nb > 9)
	ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

void	ft_puthexa(int n, char *base)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb > 9)
	ft_puthexa(nb / 16, base);
	write(1, &base[nb % 16], 1);
}
