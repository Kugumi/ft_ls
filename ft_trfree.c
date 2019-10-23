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

/*void	ft_dirfree(t_ree_dir *td)
{
	t_ree_dir *l;
	t_ree_dir *r;

	if (td != NULL)
	{
		ft_dirfree(td->left);
		r = td->right;
		free(td->path);
		free(td->dname);
		if (td->s)
			free(td->s);
		free(td);
		ft_dirfree(r);
	}
}

void	ft_trfree(t_ree_trdirs *tua)
{
	t_ree_trdirs *l;
	t_ree_trdirs *r;

	if (tua != NULL)
	{
		ft_trfree(tua->left);
		r = tua->right;
		ft_dirfree(&(tua->tr_dir));
		free(tua->tdname);
		free(tua);
		ft_trfree(r);
	}
}*/

void 	freememdir(t_ree_dir *td, t_flags *fl)
{
	int i;
//	int j;

//	j = 0;
	i = 0;
	if (td == NULL)
		return ;
	freememdir(td->left, fl);
	freememdir(td->right, fl);
	if (td->path)
	{
		i = 1;
		free(td->path);
		td->path = NULL;
	}
	if (td->dname)
	{
		free(td->dname);
		td->dname = NULL;
	}
	if (td->s)
	{
		free(td->s);
		td->s = NULL;
//		j = 1;
	}
	//if (td->fft)
	//{
//		if (fl->reci)
//			free(td->fofreetdr);
		if (td->fft)
			free(td->fofreetd);
		else
			free(td);
//		td->left = NULL;
//		td->right = NULL;
	//}
}

void	freemem(t_ree_trdirs *tua, t_flags *fl)
{
	if (tua == NULL)
		return ;
	freemem(tua->left, fl);
	freemem(tua->right, fl);
	free(tua->tdname);
	freememdir(&(tua->tr_dir), fl);
//	if (tua->fftu)
//		free(tua);
//	free(tua->tr_dir.fofreetdr);
//	free(tua->tr_dir.fofreetd);
//	free(tua->tdname);
//	tua->tdname = NULL;
//	tua->left = NULL;
//	tua->right = NULL;
	free(tua);
}
