/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 14:06:20 by fteuber           #+#    #+#             */
/*   Updated: 2014/10/03 19:06:52 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list				*sort_list(t_parameters *params)
{
	t_list			*info;
	t_list			*save;
	char			*temp;
	struct s_info	*temp_info;

	save = params->path;
	info = save;
	while (info->next)
	{
		if (ft_strcmp(info->path, info->path->next) > 0)
		{
			temp = info->path;
			info->path = info->next->path;
			info->next->path = temp;
			temp = info->name;
			info->name = info->next->name;
			info->next->name = temp;
			temp_info = info->info;
			info->info = info->next->info;
			info = save;
		}
		else
			info = info->next;
	}
	return (save);
}

t_list				*sort_reverse_list(t_parameters *params)
{
	t_list			*info;
	t_list			*save;
	char			*temp;
	struct s_info	*temp_info;

	save = params->paths;
	info = save;
	while (info->next)
	{
		if (ft_strcmp(info->path, info->path->next) < 0)
		{
			temp = info->path;
			info->path = info->path->next;
			info->path->next = temp;
			temp = info->name;
			info->name = info->next->name;
			info->next->name = temp;
			temp_info = ino->info;
			info->info = info->next->info;
			info = save;
		}
		else
			info = info->next;
	}
	return (save);
}

t_list				*sort_time(t_parameters *params)
{
	t_list			*info;
	t_list			*save;
	char			*temp;

	save = params->paths;
	info = save;
	while (info->next)
	{
		if (info->)
	}
}

t_list				*add_link(t_list *list, char *data)
{
	t_list			*new_link;
	new_link = (t_list *)malloc(sizeof(t_list));
	if (new_link)
	{
		new_link->path = data;
		new_link->next = list;
	}
	return (new_link);
}
