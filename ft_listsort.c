#include "ft_ls.h"
/*  void    ft_swap(char **a, char **b)
{
    char *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}*/
/*  char    *ft_strdup(const char *s1)
{
    int            i;
    char        *f;
    char        *new;
    const char    *s;

    s = s1;
    i = 0;
    while (*s)
    {
        s++;
        i++;
    }
    new = (char *)malloc(sizeof(char) * i + 1);
    if (new == 0)
        return (NULL);
    f = new;
    while (*s1)
    {
        *new = *s1;
        new++;
        s1++;
    }
    *new = '\0';
    return (f);
}*/
/*  typedef struct s_list
{
    char *content;
    size_t content_size;
    struct s_list *next;
}    t_list;*/
/*  int comp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}*/

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
/*  int main()
{
    t_list *a;
    t_list *b;

    a = (t_list *)malloc(sizeof(t_list));
    b = a;
    a->content = ft_strdup("ball");
    a->next = (t_list *)malloc(sizeof(t_list));
    a = a->next;
    a->content = ft_strdup("maton");
    a->next = (t_list *)malloc(sizeof(t_list));
    a = a->next;
    a->content = ft_strdup("aab");
    a->next = (t_list *)malloc(sizeof(t_list));
    a->next = NULL;
    b = ft_lstsort(b);
    while (b->next)
    {
        printf("%s", b->content);
        b = b->next;
    }
}*/
