#include "libft.h"

double	ft_atof(const char *str)
{
	double	integ;
	double	dec;
	char	*c;
	int		len;

	c = (char *)str;
	integ = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	dec = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		dec /= 10;
	return (integ + ((integ > 0) ? dec : -dec));
}