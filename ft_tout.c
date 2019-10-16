/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 02:17:05 by jijerde           #+#    #+#             */
/*   Updated: 2019/09/28 01:57:00 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	treeprint(t_ree_dir *td, t_flags *fl)
{
	if (td != NULL)
	{
		treeprint (td->left, fl);
		if (td->s != NULL)
		{
			printf("ls: %s: %s\n", td->dname, td->s);
		}
		else if (td->dname != NULL)
			printf("%s\n", td->dname);
		treeprint(td->right, fl);
	}
}

void	findtree(t_ree_trdirs *tua, t_flags *fl, int argc)
{
	if (tua != NULL)
	{
		findtree(tua->left, fl, argc);
		if (fl->rec && fl->fir)
			printf("%s:\n", tua->tdname);
		else if (argc > 2)
            printf("%s:\n", tua->tdname);
		fl->fir = 1;
		treeprint(&(tua->tr_dir), fl);
		write(1, "\n", 1);
		findtree(tua->right, fl, argc);
	}
}
