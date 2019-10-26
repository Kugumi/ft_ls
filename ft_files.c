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

void	filesprint(t_ree_files *tf, t_signs *fl, t_trpointers *tp)
{
	if (tf != NULL)
	{
		filesprint(tf->left, fl, tp);
		if (!fl->l)
			ft_printf("%s\n", tf->fname);
		else if (fl->l)
			ft_filelprint(tf, tp);
		filesprint(tf->right, fl, tp);
	}
}

void	ft_filesr(t_trpointers *tp, char *name, t_signs *fl)
{
	if (!fl->tfr && ft_notfr(tp, name, fl))
		return ;
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
	if (!fl->tfr && ft_notfr(tp, name, fl))
		return ;
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

void	ft_filesrt(t_trpointers *tp, char *name, t_signs *fl)
{
	if (!fl->tfr && ft_notfr(tp, name, fl))
		return ;
	while (1)
	{
		if (tp->tf->sec >= tp->tsec)
		{
			if (tp->tf->left == NULL)
			{
				tp->tf->left = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (tp->tf->sec < tp->tsec)
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

void	ft_filest(t_trpointers *tp, char *name, t_signs *fl)
{
	if (!fl->tfr && ft_notfr(tp, name, fl))
		return ;
	while (1)
	{
		if (tp->tf->sec < tp->tsec)
		{
			if (tp->tf->left == NULL)
			{
				tp->tf->left = filltf(tp->tf, name, fl, tp);
				break ;
			}
			else
				tp->tf = tp->tf->left;
		}
		if (tp->tf->sec >= tp->tsec)
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
