#include "../../includes/ft_21sh.h"

int			ft_putchr_fd(int n)
{
	write(2, &n, 1);
	return (1);
}

int			ft_putst_fd(char *str)
{
	while (*str)
		ft_putchr_fd(*str++);
	return (1);
}

struct termios	*default_config(struct termios *def, char type)
{
	static struct termios *tp;

	if (type == 's')
		tp = def;
	else if (type == 'g')
		return (tp);
	return (NULL);
}

void		ft_noncanon_on()
{
	char		*term_type;
	struct termios tp;
	struct termios sp;

	term_type = getenv("TERM");
	tgetent(NULL, term_type);
	tcgetattr(0, &tp);
	sp = tp;
	default_config(&tp, 's');
	sp.c_lflag &= ~(ICANON | ECHO);
	sp.c_cc[VTIME] = 0;
	sp.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &sp);
	tputs(tgetstr("cl", NULL), 1, ft_putchr_fd);
}

int			ft_cmd_management()
{
	char		b[0];

	while (1)
	{
		ft_putst_fd(line);
	}
	tcsetattr(0, TCSANOW, default_config(NULL, 'g'));
}

int		main(void)
{
	ft_cmd_management();
	return  (0);
}