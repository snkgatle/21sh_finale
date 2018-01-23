#include "../../includes/ft_21sh.h"

int		ft_token_expr(char *characters)
{
	bool	cmd;
	bool	dir;
	char 	*tmp;

	cmd = true;
	dir = false;
	while (*characters)
	{
		if (cmd && ft_isalnum(*characters))
		{
			cmd = false;
			dir = true;
			ft_putendl("Command Starting");
			characters = ft_search_alnum_end(characters);
			tmp = characters;
			if (*tmp && *tmp != ' ' && *tmp != '\t' && *tmp != '|' && *tmp != '<' && *tmp != '>')
			{
				ft_putendl("Error: syntax error");
				exit(0);
			}
		}
		else if (*characters == '|')
		{
			ft_putendl("Pipe and checking");
			cmd = true;
			dir = false;
			characters++;
			if (*characters && !ft_isalnum(*characters) && *characters != ' ')
			{
				ft_putendl("Error: syntax error");
				exit(0);
			}
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