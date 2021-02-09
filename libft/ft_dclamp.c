#include "libft.h"

double			ft_dclamp(double min, double max, double value)
{
	if (value < min)
	return (min);
	if (value > max)
	return (max);
	return (value);
}