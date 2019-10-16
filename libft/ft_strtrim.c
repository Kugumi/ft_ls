/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 04:18:20 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/28 01:48:14 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	ft_finish(const char *s, int i)
{
	int f;

	f = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		f++;
	}
	return (f);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		st;
	int		f;
	char	*new;
	char	*finish;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	st = ft_start(s);
	f = ft_finish(s, len - 1);
	len = len - st - f;
	if (len < 0)
		new = (char *)malloc(sizeof(char));
	else if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	finish = new;
	while (len-- > 0)
	{
		*new = s[st++];
		new++;
	}
	*new = '\0';
	return (finish);
}
