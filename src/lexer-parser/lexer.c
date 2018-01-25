#include "../../includes/ft_21sh.h"

static int		ft_error_func(int errno)
{
	ft_putstr("Error: ");
	if (errno == 1)
		ft_putendl("syntax error check if you typed the right command");
	if (errno == 2)
		ft_putendl("syntax error characters specified not allowed");
	return (1);
}

int		ft_token_expr(char *characters, t_lex *info)
{
	char 	*cmp;
	char 	*tmp;

	cmp = NULL;
	tmp = NULL;
	info->characters = characters;
	while (*(info->characters))
	{
		tmp = info->characters;
		if (info->cmd && !(cmp = ft_cmd_lexer(info)) && ft_error_func(1))
			return (0);
		else if (*tmp == ';' && !(cmp = ft_sepa_lexer(info)) && ft_error_func(2))
			return (0);
		else if (*tmp == '|' && !(cmp = ft_pipe_lexer(info)) && ft_error_func(3))
			return (0);
		if (!(*(info)->characters))
		{
			ft_add_node(&info->hd, ft_new_node(cmp, false, false, false));
			return (1);
		}
		ft_add_node(&info->hd, ft_new_node(cmp, false, false, false));
		cmp = NULL;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_lex	info;
	t_linfo *p_hd;

	info.cmd = true;
	info.dir = false;
	info.opt = false;
	info.hd = NULL;
	ac = 0;
	ft_token_expr(*(av + 1), &info);
	p_hd = info.hd;
	while (p_hd)
	{
		ft_putendl(p_hd->cmd);
		p_hd = p_hd->next;
	}
	return (0);
}