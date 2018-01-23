#include "libft.h"

void		ft_2dfree(void **data)
{
	void *p_data;

	if (!data || !*data)
		return ;
	p_data = data;
	while (*data)
	{
		free(*data);
		data++;
	}
	free(p_data);
}