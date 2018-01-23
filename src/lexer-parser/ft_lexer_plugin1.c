#include "../../includes/ft_21sh.h"


static int	ft_executable(char *tmp, char **paths, char *dir_ex)
{
	char **p_paths;

	p_paths = NULL;
	tmp = getenv("PATH");
		if (!(paths = ft_strsplit(tmp, ':')))
		{
			ft_strdel(&dir_ex);
			return (0);
		}
		p_paths = paths;
		while (paths && *paths)
		{
			tmp = ft_strjoin(*paths, dir_ex);
			if (!(access(tmp, X_OK | F_OK)))
			{
				ft_strdel(&tmp);
				ft_2dfree((void **)p_paths);
				ft_strdel(&dir_ex);
				return (1);
			}
			ft_strdel(&tmp);	
			paths++;
		}
		ft_strdel(&dir_ex);
		ft_2dfree((void **)p_paths);	
}

static int	ft_folder_file(char *ex_or_file, char *dir_ex)
{
	if (ex_or_file && ex_or_file[0] == '~')
		dir_ex = ft_strjoin(getenv("HOME"), ex_or_file + 1);
	if (!dir_ex && !(access(ex_or_file, F_OK | R_OK)))
		return (1);
	else if (dir_ex && !access(dir_ex, F_OK | R_OK))
	{
		ft_strdel(&dir_ex);
		return (1);
	}
	ft_strdel(&dir_ex);
	return (0);
}

int			ft_check_file_ex(char *ex_or_file, char type)
{
	char	*tmp;
	char	**paths;
	char	**p_paths;
	char	*dir_ex;

	paths = NULL;
	tmp = NULL;
	dir_ex = NULL;
	if (type == 'f')
	{
		if (ft_folder_file(ex_or_file, dir_ex))
			return (1);
		ft_putendl("File or directory not found");
		return (0);
	}
	else if (type == 'e')
	{
		dir_ex = ft_strjoin("/", ex_or_file);
		if (ft_executable(tmp, paths, dir_ex))
			return (1);	
		ft_putendl("Command not found / permission denied");
	}
	return (0);
}