/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 14:06:20 by fteuber           #+#    #+#             */
/*   Updated: 2014/09/29 14:06:22 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*add_link(t_list *list, char *data)
{
	t_list		*new_link;
	new_link = (t_list *)malloc(sizeof(t_list));
	if (new_link)
	{
		new_link->path = data;
		new_link->next = list;
	}
	return (new_link);
}
