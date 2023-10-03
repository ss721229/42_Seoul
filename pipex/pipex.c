/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42seoul.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:53:42 by sanseo            #+#    #+#             */
/*   Updated: 2023/09/27 19:15:47 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_process(char **argv, char **envp, int *fd)
{
	int infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error("infile open error");
	// 파일 디스크립터 복제 및 재지정
	// 자식 프로세스의 표준 입력을 입력 파일로 재지정하여
	// 첫 번째 명령어가 입력 파일에서 데이터를 읽도록 함
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error("child dup2 error!");
	// fd[1]은 파이프의 write end
	// 자식 프로세스의 표준 출력을 파이프의 write end로 재지정하여
	// 첫 번째 명령어의 출력이 파이프로 이동하도록 함
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("child dup2 error!");
	// 자식 프로세스에서는 read end를 사용하지 않으므로 닫아줌
	if (close(fd[0]) == -1)
		ft_error("child close error!");
	// argv[2] 명령어를 실행
	execute_cmd(argv[2], envp);
}

void parent_process(char **argv, char **envp, int *fd)
{
	int outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
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

int main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		ft_error("argument number error!");
	else
	{
		// 파이프 생성, 파이프는 두 개의 파일 디스크립터 반환
		// fd[0]은 파이프의 read end, fd[1]은 파이프의 write end
		if (pipe(fd) == -1)
			ft_error("pipe error!");

		// 현재 프로세스를 복제하고 부모 프로세스와 자식프로세스 생성
		// 부모 프로세스는 자식 프로세스의 PID, 자식 프로세스는 0
		// 여기 이후부터 프로세스가 두 개가 실행됨
		pid = fork();
		if (pid == -1) // 실패시 -1 
			ft_error("fork error!");
		else if (pid == 0) // 자식 프로세스만 실행
			child_process(argv, envp, fd);
		else // 부모 프로세스만 실행
		{
			if (waitpid(pid, 0, 0) == -1)
				ft_error("waitpid error!");
			parent_process(argv, envp, fd);
		}
	}
	return (0);
}