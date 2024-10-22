/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:19:27 by lpittigl          #+#    #+#             */
/*   Updated: 2024/10/05 22:19:28 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	destroy_matrix(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free (array[i++]);
	free (array);
}

void	handle_error(char *s, char **array1, char **array2)
{
	ft_putendl_fd(s, 2);
	if (array1)
		destroy_matrix(array1);
	if (array2)
		destroy_matrix(array2);
	exit(-1);
}

char	**set_up(char *cmd, char **envp)
{
	int		i;
	char	**comands;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	comands = ft_split(envp[i] + 5, ':');
	i = 0;
	while (comands[i])
	{
		comands[i] = ft_strjoin(comands[i], "/");
		comands[i] = ft_strjoin(comands[i], cmd);
		i++;
	}
	return (comands);
}
