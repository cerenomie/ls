/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 14:19:50 by fteuber           #+#    #+#             */
/*   Updated: 2014/09/30 11:21:23 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_get_pwd(t_parameters *params, char **envp)
{
	int		i;

	(void)params;
	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'W' && envp[i][2] == 'D' &&
				envp[i][3] == '=')
		{
			params->pwd = &envp[i][4];
			break;
		}
		i++;
	}
	printf("%s\n", params->pwd);
}
