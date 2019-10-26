/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 02:17:33 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/12 03:24:35 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	freedirs(t_dirs *dirs)
{
	t_dirs *buff;

	while (dirs)
	{
		free(dirs->name);
		buff = dirs->next;
		free(dirs);
		dirs = buff;
	}
}

void	freel(t_ree_dir *td, t_signs *fl, int i, int j)
{
	if ((fl->l || fl->t) && i && !j && td->gg)
	{
		free(td->time);
		if (fl->l)
		{
			free(td->uid);
			free(td->gid);
			free(td->rwx);
			if (td->buff)
				free(td->buff);
		}
	}
	if (td->fft)
		free(td->fofreetd);
	else
		free(td);
}

void	freememdir(t_ree_dir *td, t_signs *fl, t_trpointers *tp)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (td == NULL)
		return ;
	freememdir(td->left, fl, tp);
	freememdir(td->right, fl, tp);
	if (td->path && (i = 1))
	{
		free(td->path);
		td->path = NULL;
	}
	if (td->dname)
	{
		free(td->dname);
		td->dname = NULL;
	}
	if (td->s && (j = 1))
	{
		free(td->s);
		td->s = NULL;
	}
	freel(td, fl, i, j);
}

void	freememfiles(t_ree_files *tf, t_signs *fl)
{
	if (tf == NULL)
		return ;
	freememfiles(tf->left, fl);
	freememfiles(tf->right, fl);
	if (tf->fname)
	{
		free(tf->fname);
		tf->fname = NULL;
	}
	if (fl->l || fl->t)
	{
		free(tf->time);
		if (fl->l)
		{
			free(tf->uid);
			free(tf->gid);
			free(tf->rwx);
			if (tf->buff)
				free(tf->buff);
		}
	}
	free(tf);
}
