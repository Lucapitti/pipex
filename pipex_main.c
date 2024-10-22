/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittigl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:20:30 by lpittigl          #+#    #+#             */
/*   Updated: 2024/10/05 22:20:31 by lpittigl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char **envp, char *comand_line)
{
	char	**cmd;
	char	**comand;
	int		i;

	i = 0;
	cmd = ft_split(comand_line, ' ');
	comand = set_up(cmd[0], envp);
	while (comand[i] && access(comand[i], X_OK))
		i++;
	if (comand[i] && cmd)
	{
		if (execve(comand[i], cmd, envp) == -1)
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			handle_error(cmd[0], comand, cmd);
		}
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	handle_error(cmd[0], comand, cmd);
}

void	child_process(int *pipe_fd, char **argv, char **envp)
{
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		if (errno == ENOENT)
			ft_putstr_fd("pipex: no such file or directory: ", 2);
		if (errno == EACCES)
			ft_putstr_fd("pipex: permission denied: ", 2);
		handle_error(argv[1], NULL, NULL);
	}
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	exec(envp, argv[2]);
}

void	parent_process(int *pipe_fd, char **argv, char **envp)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		if (errno == EACCES)
			ft_putstr_fd("pipex: permission denied: ", 2);
		else
			ft_putstr_fd("pipex: impossible to create such file: ", 2);
		handle_error(argv[4], NULL, NULL);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	exec(envp, argv[3]);
}

int	main(int argc, char **argv, char **envp)
{
	__pid_t	pid;
	int		pipe_fd[2];

	if (argc != 5)
		handle_error("./pipex file1 cmd1 cmd2 file2", NULL, NULL);
	if (pipe(pipe_fd) == -1)
		exit (1);
	pid = fork();
	if (pid == -1)
		exit (1);
	if (pid == 0)
		child_process(pipe_fd, argv, envp);
	else
		parent_process(pipe_fd, argv, envp);
	waitpid(pid, NULL, 0);
	return (0);
}
