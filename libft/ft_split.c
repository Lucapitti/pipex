/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:26:21 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/20 17:26:23 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;
	size_t	valid;

	i = 0;
	count = 0;
	valid = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			if (!valid)
				continue ;
			count++;
			valid = 0;
			continue ;
		}
		if (str[i++] == '\'')
			while (str[i] && str[i] != '\'')
				i++;
		valid = 1;
	}
	return (count + valid);
}

static size_t	len_word(const char *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[len + i] != 0 && s[len + i] != c)
	{
		if (s[i + len++] == '\'')
			while (s[len + i] != 0 && s[len + i] != '\'')
				len++;
	}
	return (len);
}

void	remove_ap(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i + 1] == '\'')
			str[i + 1] = 0;
		str[i] = str[i + 1];
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	j;
	size_t	i;

	if (!s)
		return (NULL);
	final = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			final[j] = ft_substr(s, (unsigned int)i, len_word(s, c, i));
			if (final[j++][0] == '\'')
				remove_ap(final[j - 1]);
			i += len_word(s, c, i);
		}
	}
	final[j] = NULL;
	return (final);
}
