/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:10:25 by jeshin            #+#    #+#             */
/*   Updated: 2024/05/13 14:42:38 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	_env(void)
{
	t_node	*here;

	here = g_env.head;
	while (here)
	{
		if (here->val && ft_strncmp(here->name, "?", 2) != EXIT_SUCCESS)
		{
			ft_putstr(here->name);
			write(1, "=", 1);
			ft_putstr(here->val);
			write(1, "\n", 1);
		}
		here = here->next;
	}
	return (EXIT_SUCCESS);
}
