#include "libft.h"

double ft_fabs(double value)
{
    if (value < 0)
    value *= -1.0;
    return (value);
}