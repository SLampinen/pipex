/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:09:16 by slampine          #+#    #+#             */
/*   Updated: 2023/04/26 10:09:17 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>

void	dup_n_close(int *tab, int file, int num);
char	*get_path_line(char **env);
char	*get_cmd_path(char *path_line, char *cmd);
void	first_child(char **src, int *pipe_fd, char **env);
void	second_child(char **src, int *pipe_fd, char **env);

#endif