#include "../../includes/ft_21sh.h"

char 	*ft_cmd_lexer(t_lex *info)
{
	char 	*cmd;
	char 	*tmp;

	if (!info->cmd || !*(info->characters))
		return (NULL);
	cmd = NULL;
	tmp = NULL;
	info->cmd = false;
	info->dir = true;
	info->characters = ft_skip_spaces(info->characters);
	tmp = ft_search_alnum_end(info->characters);
	if (tmp != info->characters)
		cmd = ft_strsub(info->characters, 0, tmp - info->characters);
	else
		return (NULL);
	if (!ft_check_file_ex(cmd, 'e'))
	{
		ft_strdel(&cmd);
		return (NULL);
	}
	info->characters = ft_search_alnum_end(info->characters);
	info->characters = ft_skip_spaces(info->characters);
	if (!*(info->characters))
		return (cmd);
	if (!ft_strchr("></|;", *(info->characters)) && !ft_isalnum(*(info->characters)))
	{
		ft_strdel(&cmd);
		return (NULL);
	}
	return (cmd);
}