/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:04:29 by jeshin            #+#    #+#             */
/*   Updated: 2024/05/13 18:39:34 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_ended_with_pipe(char *buf)
{
	int		i;
	char	*here;

	if (buf == 0)
		return (FALSE);
	here = ft_strrchr(buf, '|');
	if (here == NULL)
		return (FALSE);
	i = ft_strlen(buf);
	while (--i)
	{
		if (ft_isspace(buf[i]))
			continue ;
		if (&(buf[i]) > here)
			return (FALSE);
	}
	return (TRUE);
}

static int	is_all_space(char *buf)
{
	int		i;

	if (buf == 0)
		return (FALSE);
	i = -1;
	while (buf[++i])
	{
		if (ft_isspace(buf[i]))
			continue ;
		if (buf[i])
			return (FALSE);
	}
	return (TRUE);
}

static void	get_extra_buf(char **buf)
{
	char	*tmp1;

	while (is_ended_with_pipe(*buf))
	{
		tmp1 = readline("> ");
		if (tmp1 == 0)
		{
			if (ft_strlen(*buf))
				add_history(*buf);
			if (*buf)
			{
				free(*buf);
				*buf = 0;
			}
			write(1, "\033[1A", 4);
			write(1, "\033[2C", 4);
			ft_putstr_fd("bash: syntax error: unexpected end of file\n", 2);
			return ;
		}
		*buf = ft_strjoin(*buf, tmp1);
	}
}

static void	exit_when_eof(void)
{
	write(1, "\033[1A", 4);
	write(1, "\033[10C", 5);
	write(1, "exit\n", 5);
	rl_clear_history();
	exit(EXIT_SUCCESS);
}

int	check_buf(char **buf)
{
	char	*tmp;

	if (*buf == 0)
		exit_when_eof();
	if (**buf == 0 || is_all_space(*buf))
	{
		free(*buf);
		return (EXIT_FAILURE);
	}
	if (check_syntax_err(*buf) || **buf == '|')
	{
		ft_putstr_fd("--------------bash: syntax error near unexpected token `|'\n", 2);
		free(*buf);
		update_prev_status(258);
		return (EXIT_FAILURE);
	}
	if (is_ended_with_pipe(*buf))
		get_extra_buf(buf);
	if (*buf == 0)
		return (EXIT_FAILURE);
	add_history(*buf);
	tmp = ft_strdup(*buf);
	free(*buf);
	*buf = tmp;
	return (EXIT_SUCCESS);
}
