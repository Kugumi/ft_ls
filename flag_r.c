/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 07:46:16 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/19 07:46:52 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
t_ree_dir	*ft_dirr(char *name, t_flags *fl, t_ree_dir	*tr_trees)
{
	DIR 			*di;
	struct dirent 	*dp;
	t_ree_dir				*td_root;
	t_ree_dir				*td;

	if ((di = opendir(name)) == NULL)
	{
		fl->terd = 1;
		tr_trees = ft_errd(tr_trees, strerror(errno), name, fl);
		tr_trees->fofreetd = tr_trees;
		tr_trees->fft = 1;
		if (fl->rec && fl->fir)
			printf("%s:\n", name);
		else if (fl->ac > 2)
			printf("%s:\n", name);
		fl->fir = 1;
		treeprint(tr_trees, fl);
		write(1, "\n", 1);
		return (tr_trees);
	}
	if ((dp = readdir(di)) != NULL)
	{
		if (!fl->tds && fl->a)
		{
			fl->tds = 1;
			tr_trees = filltd(tr_trees, dp->d_name, name);
			td = tr_trees;
			td_root = td;
			tr_trees->fofreetd = tr_trees;
			tr_trees->fft = 1;
		}
		while ((dp = readdir(di)) != NULL)
		{
			if (dp->d_name[0] == '.' && !(fl->a))
				;
			else
			{
				if (!fl->tds)
				{
					fl->tds = 1;
					tr_trees = filltd(tr_trees, dp->d_name, name);
					td = tr_trees;
					td_root = td;
					tr_trees->fofreetd = tr_trees;
					tr_trees->fft = 1;
				}
				else
				{
					td = td_root;
					while (1)
					{
						if (strcmp(td->dname, dp->d_name) < 0)
						{
							if (td->left == NULL)
							{
								td->left = filltd(td, dp->d_name, name);
								//if (fl->reci)
								/*tr_trees->fofreetdr = td->left;
								tr_trees->fft = 1;*/
								break;
							}
							else
								td = td->left;
						}
						if (strcmp(td->dname, dp->d_name) >= 0)
						{
							if (td->right == NULL)
							{
								td->right = filltd(td, dp->d_name, name);
								//if (fl->reci)
								/*tr_trees->fofreetdr = td->right;
								tr_trees->fft = 1;*/
								break;
							}
							else
								td = td->right;
						}
					}
				}
			}
		}
		closedir(di);
		if (fl->tds == 0)
		{
			tr_trees = fillemp(tr_trees);
			tr_trees->fofreetd = tr_trees;
			tr_trees->fft = 1;
		}
		else
			fl->tds = 0;
	}
	if (fl->rec && fl->fir)
		printf("%s:\n", name);
	else if (fl->ac > 2)
		printf("%s:\n", name);
	fl->fir = 1;
	treeprint(tr_trees, fl);
	write(1, "\n", 1);
	return (tr_trees);
}

/*void    ft_treedirsr(char *name, t_flags *fl, t_trpointers *tp)
{
	if (!fl->tdr)
	{
		tp->tr_td = filltu(tp->tr_td, name, fl);
		*//*if (tp->tr_tda.tr_dir.dname == 0)
		{
			free(tp->tr_tda.tdname);
			free(&(tp->tr_tda));
			return ;
		}
		//tp->tr_td = &(tp->tr_tda);*//*
		tp->tr_tdroot = tp->tr_td;
		fl->tdr = 1;
		return ;
	}
	tp->tr_td = tp->tr_tdroot;
	while(1)
	{
		if (strcmp(tp->tr_td->tdname,name) < 0)
		{
			if (tp->tr_td->left ==  NULL)
			{
				tp->tr_td->left = filltu(tp->tr_td, name, fl);
				*//*if (tp->tr_td->left->tr_dir.dname == 0)
				{
					free(tp->tr_td->left->tdname);
					free(tp->tr_td->left);
					tp->tr_td->left = NULL;
					return ;
				}*//*
				break ;
			}
			else
				tp->tr_td = tp->tr_td->left;
		}
		if (strcmp(tp->tr_td->tdname, name) >= 0)
		{
			if (tp->tr_td->right == NULL)
			{
				tp->tr_td->right = filltu(tp->tr_td, name, fl);
				*//*if (tp->tr_td->right->tr_dir.dname == 0)
				{

					return ;
				}*//*
				break ;
			}
			else
				tp->tr_td = tp->tr_td->right;
		}
	}
}*/

/*void	ft_rrr(t_ree_dir *td, t_flags *fl, t_trpointers *tp)
{
	struct stat	stbuf;
	char *tmp;

	if (td != NULL)
	{
		ft_rrr(td->right, fl, tp);
		if (td->dname != NULL)
		{
			if ((strcmp(td->dname, ".") != 0 && strcmp(td->dname, "..") != 0) && !(td->s))
			{
				tmp = ft_strjoinp(td->path, td->dname);
				free(td->path);
				td->path = tmp;
				lstat(td->path, &stbuf);
				*//*if (lstat(td->path, &stbuf) == -1)
				{
					//ft_errd(tp->tr_tda.tr_dir.tr_err, td->path, strerror(errno), fl);
					//printf("ft_ls: %s: %s\n", td->path, strerror(errno));
					return;
				}*//*
				if ((stbuf.st_mode & S_IFMT) == S_IFDIR && (strcmp(td->dname, ".") != 0 && strcmp(td->dname, "..") != 0))
				{
					fl->reci = 1;
					if (!fl->r)
						ft_treedirs(td->path, fl, tp);
					else
						ft_treedirsr(td->path, fl, tp);
				}
			}
		}
		ft_rrr(td->left, fl, tp);
	}
}*/

/*
void	ft_r1(t_ree_trdirs *tua, t_flags *fl, t_trpointers *tp)
{
	if (tua != NULL)
	{
		ft_r1(tua->right, fl, tp);
		ft_rrr(&(tua->tr_dir), fl, tp);
		ft_r1(tua->left, fl, tp);
	}
}*/
