#include "../../includes/ft_21sh.h"

char 		*ft_pipe_lexer(t_lex *info)
{
	if (info->cmd)
		return (NULL);
	info->cmd = true;
	info->dir = false;
	info->characters = info->characters + 1;
	info->characters = ft_skip_spaces(info->characters);
	if (*(info->characters) == '|')
		return (NULL);
	if (!ft_isalnum(*(info->characters)) && *(info->characters) != '\0')
		return (NULL);
	else
		return (ft_strdup("|"));
}
