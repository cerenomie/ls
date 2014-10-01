/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 14:06:25 by fteuber           #+#    #+#             */
/*   Updated: 2014/09/29 18:19:00 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <stdio.h>

typedef struct				s_list
{
	char					*path;
	struct s_list			*next;
}							t_list;

typedef struct				s_parameters
{
	int						parameters[5];
	char					*pwd;
	t_list					*paths;
}							t_parameters;


t_list						*add_link(t_list *list, char *data);
int							ft_strlen(char *str);
char						*ft_strjoin(char *s1, char *s2);
void						ft_check_path(t_parameters *params, char *path);
void						ft_get_pwd(t_parameters *params, char **envp);
#endif
