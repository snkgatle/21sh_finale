#include "../../includes/ft_21sh.h"

t_linfo			*ft_new_node(char *cmd_op, bool start, bool end, bool valid)
{
	t_linfo *info;

	if (!(info = (t_linfo *)malloc(sizeof(t_linfo))))
		return (NULL);
	info->cmd = cmd_op;
	info->first = start;
	info->last = end;
	info->valid = valid;
	info->next = NULL;
	return (info);
}

void			ft_add_node(t_linfo **hd, t_linfo *new_node)
{
	t_linfo *p_hd;

	p_hd = *hd;
	if (!p_hd)
		*hd = new_node;
	else
	{
		while (p_hd->next)
			p_hd = p_hd->next;
		p_hd->next = new_node;
	}
}