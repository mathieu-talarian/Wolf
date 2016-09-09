#include "wolf.h"

void	tab_clr(char ***tab)
{
	char	**t;
	int		i;

	t = *tab;
	i = -1;
	while (t[++i])
		ft_strdel(&t[i]);
	free (t);
	t = NULL;
}
