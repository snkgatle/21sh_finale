#include "libft.h"

char			*ft_skip_spaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str && (*str == '\n' || *str == ' ' || *str == '\t'))
		str++;
	return (str);
}