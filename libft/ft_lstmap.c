/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 02:37:28 by jijerde           #+#    #+#             */
/*   Updated: 2019/01/09 21:39:37 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *finish;
	t_list *new;
	t_list *fo;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	finish = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
		{
			while (finish)
			{
				fo = finish->next;
				free(finish->content);
				free(finish);
				finish = fo;
			}
		}
		new = new->next;
	}
	return (finish);
}
