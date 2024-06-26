/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:31:11 by jeshin            #+#    #+#             */
/*   Updated: 2024/05/14 12:50:23 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_overflow(char *s)
{
	long long	ll;
	long long	prev;
	char		*set;

	set = "0123456789";
	ll = 0;
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (EXIT_FAILURE);
		prev = ll;
		ll = 10 * ll + (*s - '0');
		if (prev > ll)
			return (EXIT_FAILURE);
		s++;
	}
	return (EXIT_SUCCESS);
}

static int	has_err(char *s)
{
	int	has_space;
	int	has_num;

	has_space = 0;
	has_num = 0;
	if (check_overflow(s))
		return (TRUE);
	while (*s)
	{
		if (!ft_isdigit(*s) && !ft_isspace(*s))
			return (TRUE);
		if (has_num == 1 && has_space == 1 && !ft_isspace(*s))
			return (TRUE);
		if (ft_isdigit(*s))
			has_num = 1;
		if (ft_isspace(*s))
			has_space = 1;
		s++;
	}
	if (has_num == 0)
		return (TRUE);
	return (FALSE);
}

int	_bexit_(char **opt, t_dq *env)
{
	int	i;

	i = -1;
	while (opt[++i])
		;
	printf("exit\n");
	if (i == 1)
		exit(EXIT_SUCCESS);
	if (has_err(opt[1]))
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(opt[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	if (i == 2)
		exit(ft_atoi(opt[1]));
	if (i > 2)
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		g_status = 1;
		update_prev_status(env);
		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}

int	_exit_(char **opt)
{
	int	i;

	i = -1;
	while (opt[++i])
		;
	if (i == 1)
		exit(EXIT_SUCCESS);
	if (has_err(opt[1]))
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(opt[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	if (i == 2)
		exit(ft_atoi(opt[1]));
	if (i > 2)
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
