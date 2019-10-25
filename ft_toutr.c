/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toutr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:39:18 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/20 20:45:49 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*void	treeprintr(t_ree_dir *td, t_signs *fl)
{
	if (td != NULL)
	{
		treeprintr(td->right, fl);
		if (td->s != NULL)
		{
			printf("ls: %s: %s\n", td->dname, td->s);
		}
		else if (td->dname != NULL)
			printf("%s\n", td->dname);
		treeprintr(td->left, fl);
	}
}*/

/*void	findtreer(t_ree_trdirs *tua, t_signs *fl, int argc)
{
	if (tua != NULL)
	{
		findtreer(tua->right, fl, argc);
		if (fl->rec && fl->fir)
			printf("%s:\n", tua->tdname);
		else if (argc > 2)
            printf("%s:\n", tua->tdname);
		fl->fir = 1;
		treeprint(&(tua->tr_dir), fl, tp);
		write(1, "\n", 1);
		findtreer(tua->left, fl, argc);
	}
}*/
