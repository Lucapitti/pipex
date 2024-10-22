/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:32:27 by lpittigl          #+#    #+#             */
/*   Updated: 2024/01/16 21:36:12 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	final = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!final)
		return (NULL);
	while (*(s1 + i))
	{
		final[i] = *(s1 + i);
		i++;
	}
	free(s1);
	while (*(s2 + j))
	{
		final[i + j] = *(s2 + j);
		j++;
	}
	final[i + j] = 0;
	return (final);
}
