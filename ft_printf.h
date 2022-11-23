# ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

#  define B16 "0123456789abcdef"
#  define B16U "0123456789ABCDEF"

int	ft_printf(const char *s, ...);
int	ft_strlen(const char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putuns(unsigned int n);
void	ft_puthexa(int n, char *base);

#endif