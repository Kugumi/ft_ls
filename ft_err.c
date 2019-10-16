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

void	ft_err(char *name, char *s, t_flags *fl)
{
	t_ree_errors		*te;
	static t_ree_errors	*te_root;

	if (!fl->ter)
	{
		fl->ter = 1;
		te_root = fillte(te_root, name, s);
		return ;
	}
	te = te_root;
	while (1)
	{
		if (strcmp(te->name, name) >= 0)
		{
			if (te->left == NULL)
			{
				te->left = fillte(te, name, s);
					break ;
			}
			else
				te = te->left;
		}
		if (strcmp(te->name, name) < 0)
		{
			if (te->right == NULL)
			{
				te->right = fillte(te, name, s);
					break ;
			}
			else
				te = te->right;
		}
	}
}

t_ree_dir *ft_errd(t_ree_dir *td, char *s, char *name, t_flags *fl)
{
	td = (t_ree_dir *)malloc(sizeof(t_ree_dir));
	td->path = ft_strdup(name);
	td->dname = ft_name(name);
	td->s = ft_strdup(s);
	td->right = NULL;
	td->left = NULL;
	return (td);
}
