/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:00:55 by lpittigl          #+#    #+#             */
/*   Updated: 2024/10/07 19:00:56 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <errno.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #include <fcntl.h>
#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

char	**set_up(char *cmd, char **envp);
void	handle_error(char *s, char **array1, char **array2);
void	destroy_matrix(char **array);

#endif
