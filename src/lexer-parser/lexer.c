#include "../../includes/ft_21sh.h"

char 	*ft_cmd_lexer(char *characters, bool *cmd, bool *dir)
{
	char 	*tmp;
	char 	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	*cmd = true;
	*dir = false;
	ft_putendl("Command Starting");
	tmp = ft_search_alnum_end(characters);
	if (tmp)
		tmp2 = ft_strsub(characters, 0, tmp - characters);
	if (tmp && !(ft_check_file_ex(tmp2, 'e')))
	{
		ft_strdel(&tmp2);
		return (NULL);
	}
	ft_strdel(&tmp2);
	tmp = ft_search_alnum_end(characters);
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp && *tmp != ' ' && *tmp != '\t' && *tmp != '|' && *tmp != '<' && *tmp != '>' && *tmp != '/' && !ft_isalnum(*tmp))
	{
		ft_putendl("Error: syntax error while processing command");
		return (NULL);
	}
	return (tmp);
}

char 	*ft_pipe_lexer(char *characters, bool *cmd, bool *dir)
{
	*cmd = true;
	*dir = false;
	ft_putendl("Pipe and checking");
	characters++;
	while (*characters == ' ' || *characters == '\t')
		characters++;
	if (!*characters || (!ft_isalnum(*characters) && *characters != ' ' && *characters != '/'))
	{
		ft_putendl("Error: syntax error");
		return (NULL);
	}
	return (characters);
}

char 	*ft_sepa_lexer(char *characters, bool *cmd, bool *dir)
{
	*cmd = true;
	*dir = false;
	ft_putendl("Command separator");
	while (*characters && (*characters == ' ' || *characters == '\t'))
		characters++;
	if (*characters && !ft_isalnum(*characters))
	{
		ft_putendl("Error: syntax error");
		return (NULL);
	}
	return (characters);
}

int		ft_token_expr(char *characters)
{
	bool	cmd;
	bool	dir;
	char 	*tmp;

	cmd = true;
	dir = false;
	while (*characters == ' ' || *characters == '\t')
		characters++;
	while (*characters)
	{
		if ((*characters && cmd && ft_isalnum(*characters)) || ft_strchr(characters, '/'))
		{
			if (!(characters = ft_cmd_lexer(characters, &cmd, &dir)))
				return (0);
		}
		else if (*characters == '|')
		{
			if (!(characters = ft_pipe_lexer(characters, &cmd, &dir)))
				return (0);
		}
		else if (*characters == ';')
		{
			cmd = true;
			dir = false;
			ft_putendl("Command separator");
			if (*characters && !ft_isalnum(*characters))
			{
				ft_putendl("Error: syntax error");
				exit(0);
			}
		}
		else if (*characters == '<')
		{
			printf("Redirections stdin or heredoc");
			characters++;
			if (!*characters || (!ft_isalnum(*characters) && *characters != '<'))
			{
				ft_putendl("Error: syntax error");
				exit(0);
			}
			if (!*characters)
				return (1);
		}
		else if (*characters == '>' || ft_isdigit(*characters))
		{
			ft_putendl("Redirections or file aggregators");
			tmp = ++characters;
			ft_putstr(tmp);
			if (!*characters || (*tmp != '&' && *tmp != '-' && *tmp != '>' && !ft_isalnum(*tmp) && *tmp != ' '))
			{
				ft_putendl("Error: syntax error");
				exit(0);
			}
			characters = ft_search_alnum_end(characters);
			if (!*characters)
				return (1);
		}
		else if (dir && *characters == '-')
		{
			ft_putendl("Options inserted");
			characters = ft_search_alnum_end(characters + 1);
		}
		else
		{
			ft_putendl("Parse Error: use of forbidden characters\n");
			exit(EXIT_FAILURE);
		}
		if (*characters && (*characters == ' ' || *characters == '\t'))
		{
			characters++;
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	ac = 0;
	ft_token_expr(*(av + 1));	
	return (0);
}