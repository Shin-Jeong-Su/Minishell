/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:50:19 by jeshin            #+#    #+#             */
/*   Updated: 2024/05/17 17:27:12 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_pipe_num_from_tree(t_tree *tree)
{
	int	n;

	n = 0;
	while (tree)
	{
		if (tree->ctrl_token == PIPE)
			n++;
		tree = tree->next_right;
	}
	return (n);
}

void	my_dup2(t_subtree *subtree, int rd, int wr)
{
	if (subtree->infile_fd == STDIN_FILENO && rd != STDIN_FILENO)
	{
		if (dup2(rd, STDIN_FILENO) < 0)
			perror("dup2: ");
	}
	if (subtree->infile_fd != STDIN_FILENO)
	{
		if (dup2(subtree->infile_fd, STDIN_FILENO) < 0)
			perror("dup2: ");
	}
	if (subtree->outfile_fd == STDOUT_FILENO && wr != STDOUT_FILENO)
	{
		if (dup2(wr, STDOUT_FILENO) < 0)
			perror("dup2: ");
	}
	if (subtree->outfile_fd != STDOUT_FILENO)
	{
		if (dup2(subtree->outfile_fd, STDOUT_FILENO) < 0)
			perror("dup2: ");
	}
}

void	open_pipes(int num,	int ***pipe_fd_tab)
{
	int	**tab;
	int	i;

	if (num == 0)
		return ;
	*pipe_fd_tab = (int **)malloc(sizeof(int *) * num);
	if (*pipe_fd_tab == 0)
		perror_n_exit("malloc");
	tab = *pipe_fd_tab;
	i = -1;
	while (++i < num)
	{
		tab[i] = (int *)malloc(sizeof (int) * 2);
		if (tab[i] == 0)
			perror_n_exit("malloc");
		if (pipe(tab[i]))
			perror_n_exit("pipe");
	}
}

void	close_all_pipe(int size, int **pipe_tab)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		close(pipe_tab[i][0]);
		close(pipe_tab[i][1]);
	}
}
