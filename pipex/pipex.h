/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42seoul.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:53:16 by sanseo            #+#    #+#             */
/*   Updated: 2023/09/27 19:16:59 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

#include <stdio.h>
#include <string.h>

void	ft_free(char ***str);
void	ft_error(char *message);
char	*find_path(char *cmd, char **envp);
void	execute_cmd(char *cmd, char **envp);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);

void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
