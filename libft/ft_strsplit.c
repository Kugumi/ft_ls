/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:48:57 by jijerde           #+#    #+#             */
/*   Updated: 2018/12/28 01:49:16 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int i;
	int w;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
		if (s[i] == '\0')
			break ;
		else
			i++;
	}
	return (w);
}

static int		word_len(char const *s, char c)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				len++;
			}
			return (len);
		}
		else
		{
			while (s[i] == c)
				i++;
		}
	}
	return (len);
}

static char		*wordcpy(char const *str, char *cpy, char c)
{
	int i;
	int cp;

	cp = 0;
	i = 0;
	while (str[i] == c)
	{
		i++;
	}
	while (str[i] && str[i] != c)
	{
		cpy[cp] = str[i];
		i++;
		cp++;
	}
	cpy[cp] = '\0';
	return (cpy);
}

static char		*ft_free(char ***s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
		i++;
	}
	*s = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	char	**fresh;
	int		in;

	i = -1;
	in = 0;
	if (!s)
		return (NULL);
	if (!(fresh = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (NULL);
	while (++i < word_count(s, c))
	{
		while (s[in] == c)
			in++;
		len = word_len(&s[in], c);
		fresh[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (fresh[i] == 0)
			ft_free(&fresh);
		wordcpy(&s[in], fresh[i], c);
		in = in + len;
	}
	fresh[i] = NULL;
	return (fresh);
}
