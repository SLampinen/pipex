/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <slampine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:09:21 by slampine          #+#    #+#             */
/*   Updated: 2023/08/04 14:42:08 by slampine         ###   ########.fr       */
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

char	*get_cmd_path(char *path_line, char *cmd)
{
	char	*temp;
	char	*cmd_path;
	char	**allpaths;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	else
	{
		allpaths = ft_split(path_line, ':');
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
	}
	ft_printf("command not found: %s\n", cmd);
	exit (1);
	return (NULL);
}

void	first_child(char **src, int *pipe_fd, char **env)
{
	int		infile;
	char	*cmd_path;
	char	*path_line;
	char	**cmd_arr;

	infile = open(src[1], O_RDONLY);
	if (infile == -1)
	{
		ft_printf("no such file or directory: %s\n", src[1]);
		exit (1);
	}
	cmd_arr = ft_split(src[2], ' ');
	if (cmd_arr == NULL)
	{
		perror("");
		exit(-1);
	}
	path_line = get_path_line(env);
	cmd_path = get_cmd_path(path_line, cmd_arr[0]);
	dup_n_close(pipe_fd, infile, 0);
	execve(cmd_path, cmd_arr, env);
}
void	mid_child(char *src, char **env)
{
	
	char	*cmd_path;
	char	*path_line;
	char	**cmd_arr;

	cmd_arr = ft_split(src, ' ');
	if (cmd_arr == NULL)
	{
		perror("");
		exit(-1);
	}
	path_line = get_path_line(env);
	cmd_path = get_cmd_path(path_line, cmd_arr[0]);
	execve(cmd_path, cmd_arr, env);
}
void	last_child(int num, char **src, int *pipe_fd, char **env)
{	
	int		outfile;
	char	*cmd_path;
	char	*path_line;
	char	**cmd_arr;

	outfile = open(src[num -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("");
		exit (1);
	}
	cmd_arr = ft_split(src[num - 2], ' ');
	if (cmd_arr == NULL)
	{
		perror("");
		exit(-1);
	}
	path_line = get_path_line(env);
	cmd_path = get_cmd_path(path_line, cmd_arr[0]);
	dup_n_close(pipe_fd, outfile, 1);
	execve(cmd_path, cmd_arr, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	int		i;
	pid_t	pid;
	pid_t	pid_2;
	pid_t	pid_3;

	if (argc < 5)
	{
		ft_printf("give input as \"infile cmd1 [optional cmd(s)] cmd(n) outfile\"\n");
		return (0);
	}
	if (argc == 5)
	{
		pipe(pipe_fd);
		pid = fork();
		usleep(10);
		if (pid == -1)
			perror("Error");
		if (pid == 0)
			first_child(argv, pipe_fd, env);
		pid_2 = fork();
		usleep(10);
		if (pid_2 == -1)
			perror("Error");
		if (pid_2 == 0)
			last_child(argc, argv, pipe_fd, env);
	}
	if (argc >= 6)
	{
		i = 0;
		while (i < argc)
		{
		if (i == 1)
		{
			pipe(pipe_fd);
			pid = fork();
				usleep(10);
			if (pid == -1)
				perror("Error");
			if (pid == 0)
				first_child(argv, pipe_fd, env);
		}
		if (i >= 3 && i < argc - 2)
		{
			pid_2 = fork();
			usleep(10);
			if (pid == -1)
				perror("Error");
			if (pid == 0)
				mid_child(argv[i - 1], env);
		}
		if (i == argc - 2)
		{
			pid_3 = fork();
			usleep(10);
			if (pid_3 == -1)
				perror("Error");
			if (pid_3 == 0)
				last_child(argc, argv, pipe_fd, env);
		}
		i++;
		}
	}
	return (0);
}
