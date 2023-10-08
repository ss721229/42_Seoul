/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:53:42 by sanseo            #+#    #+#             */
/*   Updated: 2023/10/07 20:54:56 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error("infile open error");
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error("child dup2 error!");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("child dup2 error!");
	if (close(fd[0]) == -1)
		ft_error("child close error!");
	execute_cmd(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error("outfile open error");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("parent dup2 error!");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("parent dup2 error!");
	if (close(fd[1]) == -1)
		ft_error("parent close error!");
	execute_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (argc != 5)
		ft_error("argument number error!");
	else
	{
		if (pipe(fd) == -1)
			ft_error("pipe error!");
		pid = fork();
		if (pid == -1)
			ft_error("fork error!");
		else if (pid == 0)
			child_process(argv, envp, fd);
		else
		{
			if (waitpid(pid, &status, WNOHANG) == -1)
				ft_error("waitpid error!");
			parent_process(argv, envp, fd);
		}
	}
	return (0);
}
