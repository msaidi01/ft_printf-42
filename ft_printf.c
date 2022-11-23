#include "ft_printf.h"

int	check_s(va_list *p, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*p, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*p, int));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*p, int));
	else if (c == 'u')
		len += ft_putuns(va_arg(*p, unsigned int));
	else if(c == 'p')
		{
			len += write(1, "0x", 2);
			len += ft_puthexa(va_arg(*p, unsigned int), B16);
		}
	else if(c == 'x')
		len += ft_puthexa(va_arg(*p, unsigned int), B16);
	else if(c == 'X')
		len += ft_puthexa(va_arg(*p, unsigned int), B16U);
	else if(c == '%')
		len += write(1, '%', 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int	len;
	int	i;

	i = 0;
	len = 0;
	va_start(p, s);
	while(s[i])
	{
		if (s[i] != '%')
		{
			len += write(1, &s[i], 1);
			if (len < 0)
				return (-1);
		}
		if (s[i] == '%' && s[i + 1])
		{
			len += check_s(&p, s[i + 1]);
			if (len < 0)
				return (-1);
			i++;
		}
		i++;
	}
	va_end(p);
	return (len);
}
