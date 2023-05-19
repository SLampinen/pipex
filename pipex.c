/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:09:21 by slampine          #+#    #+#             */
/*   Updated: 2023/04/26 10:09:22 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_line(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH", ft_strlen(env[i])))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char **allpaths, char *cmd)
{
	char	*temp;
	char	*cmd_path;

	while (*allpaths)
	{
		temp = ft_strjoin(*allpaths, "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		allpaths++;
	}
	return (NULL);
}

void	first_child(char **src, int *pipe_fd, char **env)
{
	char	*cmd_path;
	char	*path_line;
	char	**cmd_arr;
	char	**allpaths;
	int		infile;

	infile = open(src[1], O_RDONLY);
	if (infile == -1)
	{
		perror("");
		exit (1);
	}
	usleep(1);
	cmd_arr = ft_split(src[2], ' ');
	path_line = get_path_line(env);
	allpaths = ft_split(path_line, ':');
	cmd_path = get_cmd_path(allpaths, cmd_arr[0]);
	if (cmd_path == NULL)
	{
		perror("");
		exit (1);
	}
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	dup2(infile, 0);
	execve(cmd_path, cmd_arr, env);
}

void	second_child(char **src, int *pipe_fd, char **env)
{	
	char	*cmd_path;
	char	*path_line;
	char	**cmd_arr;
	char	**allpaths;
	int		outfile;

	outfile = open(src[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		exit (1);
	}
	cmd_arr = ft_split(src[3], ' ');
	path_line = get_path_line(env);
	allpaths = ft_split(path_line, ':');
	cmd_path = get_cmd_path(allpaths, cmd_arr[0]);
	if (cmd_path == NULL)
	{
		perror("");
		exit (1);
	}
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	dup2(outfile, 1);
	execve(cmd_path, cmd_arr, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	pid_2;

	if (argc != 5)
	{
		ft_printf("Error\n");
		return (0);
	}
	pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
		first_child(argv, pipe_fd, env);
	pid_2 = fork();
	if (pid_2 == -1)
		return (0);
	if (pid_2 == 0)
		second_child(argv, pipe_fd, env);
	ft_printf("All done\n");
	return (0);
}
