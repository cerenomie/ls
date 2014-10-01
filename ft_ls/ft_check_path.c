/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 14:06:06 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/01 12:46:11 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_check_path(t_parameters *params, char *path)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin("", params->pwd);
	i = 0;
	if (path[0] == '/')
		params->paths = add_link(params->paths, path);
	else if (path[0] == '.' && path[1] == '/')
		params->paths = add_link(params->paths, ft_strjoin(params->pwd,
					&path[1]));
	else if (path[0] == '.' && path[1] == '.')
	{
		i = ft_strlen(params->pwd) - 1;
		while (params->pwd[i] >= 0)
		{
			if (params->pwd[i] == '/')
			{
				tmp[i] = '\0';
				break;
			}
			i--;
		}
		params->paths = add_link(params->paths, tmp);
	}
	else
	{
		tmp = ft_strjoin(tmp, "/");
		tmp = ft_strjoin(tmp, path);
	}
}
