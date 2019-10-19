#include "ft_ls.h"

t_dirs *ft_lstsortr(t_dirs *dirs)
{
	int l;
	int i;
	int ii;
	t_dirs *forsort2;
	t_dirs *len;
	t_dirs *nul;

	nul = dirs;
	len = dirs;
	i = 0;
	l = 1;
	while (len->next)
	{
		len = len->next;
		l++;
	}
	while (i++ < l)
	{
		ii = 0;
		dirs = nul;
		while (ii++ < (l - 1))
		{
			forsort2 = dirs->next;
			if (ft_strcmp(forsort2->name, dirs->name) > 0)
			{
				ft_swap(&(forsort2->name), &(dirs->name));
			}
			dirs = dirs->next;
		}
	}
	return (dirs);
}

t_dirs *ft_lstsort(t_dirs *dirs)
{
    int l;
    int i;
    int ii;
    t_dirs *forsort2;
    t_dirs *len;
    t_dirs *nul;

    nul = dirs;
    len = dirs;
    i = 0;
    l = 1;
    while (len->next)
    {
        len = len->next;
        l++;
    }
    while (i++ < l)
    {
        ii = 0;
        dirs = nul;
        while (ii++ < (l - 1))
        {
            forsort2 = dirs->next;
            if (ft_strcmp(forsort2->name, dirs->name) < 0)
            {
                ft_swap(&(forsort2->name), &(dirs->name));
            }
            dirs = dirs->next;
        }
    }
    return (dirs);
}