#include "rt.h"
#include "math.h"
#include "stdio.h"

int check_texture_pattern(char *name)
{
    if ((ft_strcmp(name, "checker") == 0) || (ft_strcmp(name, "split") == 0)
    || (ft_strcmp(name, "gradient") == 0) || (ft_strcmp(name, "hstripe") == 0) || (ft_strcmp(name, "vstripe") == 0) ||
    (ft_strcmp(name, "hstripe") == 0))
    return (TRUE);
    return (FALSE);
}