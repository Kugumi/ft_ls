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

void	filesprint(t_ree_files *tf)
{
	if (tf != NULL)
	{
		filesprint(tf->left);
		printf("%s\n", tf->fname);
		filesprint(tf->right);
	}
}

void	ft_files(t_trpointers *tp, char *name, t_signs *fl)
{
	//t_ree_files	*tf_root;

	if (!fl->tfr)
	{
		fl->tfr = 1;
		tp->tfroot = filltf(tp->tfroot, name);
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
				tp->tf->left = filltf(tp->tf, name);
					break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (ft_strcmp(tp->tf->fname, name) < 0)
		{
			if (tp->tf->right == NULL)
			{
				tp->tf->right = filltf(tp->tf, name);
					break ;
			}
			else
				tp->tf = tp->tf->right;
		}
	}
}
