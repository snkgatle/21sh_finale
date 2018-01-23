#include "libft.h"

char	*ft_search_alnum_end(char *str)
{
	if (!str)
		return (NULL);
	while (str && ft_isalnum(*str))
		str++;	
	return (str);
}