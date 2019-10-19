/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 05:25:33 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/03 17:59:22 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*  t_ree_dir	filltdr(t_ree_dir *td, char *name)
{
	td = (t_ree_dir *)malloc(sizeof(t_ree_dir));
	td->dname = ft_strdup(name);
	td->right = NULL;
	td->left = NULL;
	return (*td);
}*/

t_ree_dir	*fillemp(t_ree_dir *td)
{
	td->path = NULL;
	td->dname = NULL;
	td->s = NULL;
	td->fft = 0;
	td->right = NULL;
	td->left = NULL;
	return (td);
}

t_ree_dir	*filltd(t_ree_dir *td, char *name, char *p)
{
	td = (t_ree_dir *)malloc(sizeof(t_ree_dir));
	td->path = ft_strdup(p);
	td->dname = ft_strdup(name);
	td->fft = 0;
	td->s = NULL;
	td->right = NULL;
	td->left = NULL;
	return (td);
}

/*t_ree_trdirs	filltur(t_ree_trdirs *tu, char *name, t_flags *fl)
{
	tu = (t_ree_trdirs *)malloc(sizeof(t_ree_trdirs));
	tu->tdname = ft_strdup(name);
	tu->tr_dir = ft_dir(name, fl, &(tu->tr_dir));
	tu->right = NULL;
	tu->left = NULL;
	return (*tu);
}*/

t_ree_trdirs	*filltu(t_ree_trdirs *tu, char *name, t_flags *fl)
{
	tu = (t_ree_trdirs *)malloc(sizeof(t_ree_trdirs));
	tu->tdname = ft_strdup(name);
	if (!fl->r)
		tu->tr_dir= ft_dir(name, fl, &(tu->tr_dir));
	else
		tu->tr_dir= ft_dirr(name, fl, &(tu->tr_dir));
	tu->right = NULL;
	tu->left = NULL;
	return (tu);
}

t_ree_errors	*fillte(t_ree_errors *te, char *name, char *s)
{
	te = (t_ree_errors *)malloc(sizeof(t_ree_errors));
	te->name = ft_strdup(name);
	te->s = ft_strdup(s);
	te->right = NULL;
	te->left = NULL;
	return (te);
}

t_ree_files		*filltf(t_ree_files *tf, char *name)
{
	tf = (t_ree_files *)malloc(sizeof(t_ree_files));
	tf->fname = ft_strdup(name);
	tf->right = NULL;
	tf->left = NULL;
	return (tf);
}
