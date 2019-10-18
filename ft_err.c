/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 00:27:46 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/07 02:14:33 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	errprint(t_ree_errors *te)
{
    if (te != NULL)
    {
        errprint (te->left);
        printf("ls: %s: %s\n", te->name, te->s);
        errprint(te->right);
    }
}

void	ft_err(t_trpointers *tp, char *name, char *s, t_flags *fl)
{
	//t_ree_errors		*te;
	static t_ree_errors	*te_root;

	if (!fl->ter)
	{
		fl->ter = 1;
		te_root = fillte(te_root, name, s);
		return ;
	}
	tp->te = te_root;
	while (1)
	{
		if (strcmp(tp->te->name, name) >= 0)
		{
			if (tp->te->left == NULL)
			{
				tp->te->left = fillte(tp->te, name, s);
					break ;
			}
			else
				tp->te = tp->te->left;
		}
		if (strcmp(tp->te->name, name) < 0)
		{
			if (tp->te->right == NULL)
			{
				tp->te->right = fillte(tp->te, name, s);
					break ;
			}
			else
				tp->te = tp->te->right;
		}
	}
}

t_ree_dir *ft_errd(t_ree_dir *td, char *s, char *name, t_flags *fl)
{
// 	td = (t_ree_dir *)malloc(sizeof(t_ree_dir));
	td->path = ft_strdup(name);
	td->dname = ft_name(name);
	td->s = ft_strdup(s);
	td->right = NULL;
	td->left = NULL;
	return (td);
}
