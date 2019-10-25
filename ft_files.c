/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 06:58:26 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/18 07:28:39 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void 	freememfiles(t_ree_files *tf, t_signs *fl)
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
	free(tf);
}

void	filesprint(t_ree_files *tf, t_signs *fl, t_trpointers *tp)
{
	if (tf != NULL)
	{
		filesprint(tf->left, fl, tp);
		if (!fl->l)
			printf("%s\n", tf->fname);
		else if (fl->l)
		{
			printf("%s  ", tf->rwx);
			printf("%*d ",tp->lenc.c2, tf->nl);
			printf("%-*s  ", (int)tp->lenc.c3, tf->uid);
			printf("%-*s  ", (int)tp->lenc.c4, tf->gid);
			if (tf->rwx[0] == 'c' || tf->rwx[0] == 'b')
			{
				printf(" %*d, ", tp->lenc.cmajor, tf->major);
				printf("%*d ", tp->lenc.cminor, tf->minor);
			}
			else
			{
				if ((tp->lenc.cmajor > 0 || tp->lenc.cminor > 0) && (tp->lenc.cmajor + tp->lenc.cminor + 2) > tp->lenc.c5)
					printf(" %*lld", (tp->lenc.cmajor + tp->lenc.cminor + 2), tf->size);
				else
					printf("%*lld ", (int)tp->lenc.c5, tf->size);
			}
			printf("%s ", tf->time);
			if(tf->rwx[0] == 'l')
				printf("%s -> %s\n", tf->fname, tf->buff);
			else
				printf("%s\n", tf->fname);
		}
		filesprint(tf->right, fl, tp);
	}
}

void	ft_filesr(t_trpointers *tp, char *name, t_signs *fl)
{
	//t_ree_files	*tf_root;

	if (!fl->tfr)
	{
		tp->lenc = zerostruct(tp->lenc);
		fl->tfr = 1;
		tp->tfroot = filltf(tp->tfroot, name, fl, tp);
		tp->tf = tp->tfroot;
		return ;
	}
	tp->tf = tp->tfroot;
	while (1)
	{
		if (ft_strcmp(tp->tf->fname, name) < 0)
		{
			if (tp->tf->left == NULL)
			{
				tp->tf->left = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (ft_strcmp(tp->tf->fname, name) >= 0)
		{
			if (tp->tf->right == NULL)
			{
				tp->tf->right = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->right;
		}
	}
}

void	ft_files(t_trpointers *tp, char *name, t_signs *fl)
{
	//t_ree_files	*tf_root;

	if (!fl->tfr)
	{
		tp->lenc = zerostruct(tp->lenc);
		fl->tfr = 1;
		tp->tfroot = filltf(tp->tfroot, name, fl, tp);
		tp->tf = tp->tfroot;
		return ;
	}
	tp->tf = tp->tfroot;
	while (1)
	{
		if (ft_strcmp(tp->tf->fname, name) >= 0)
		{
			if (tp->tf->left == NULL)
			{
				tp->tf->left = filltf(tp->tf, name, fl, tp);
					break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (ft_strcmp(tp->tf->fname, name) < 0)
		{
			if (tp->tf->right == NULL)
			{
				tp->tf->right = filltf(tp->tf, name, fl, tp);
					break ;
			}
			else
				tp->tf = tp->tf->right;
		}
	}
}
