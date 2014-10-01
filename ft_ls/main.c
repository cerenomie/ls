/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fteuber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 14:06:13 by fteuber           #+#    #+#             */
/*   Updated: 2014/09/29 18:19:11 by fteuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//tous les printf oublie pas de mettre ft_putstr
//ps: un amie qui tu veux du bien ;)


void		ft_usage(char c)
{
	printf("ft_ls: illegal option -- %c\n", c);
	printf("usage: ls [-lRart] [file...]\n");
	exit(0);
}

void		get_parameters_type(char *str, int parameters[5])
{
	int		i;

	i = 1;
	while(str[i] != '\0')
	{
		if (str[i] == 'l')
			parameters[0] = 1;
		else if (str[i] == 'R')
			parameters[1] = 1;
		else if (str[i] == 'a')
			parameters[2] = 1;
		else if (str[i] == 'r')
			parameters[3] = 1;
		else if (str[i] == 't')
			parameters[4] = 1;
		else
			ft_usage(str[i]);
		i++;
	}
}

void		ft_set_parameters(int argc, char **argv, t_parameters *params)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && i == 1)
			get_parameters_type(argv[i], params->parameters);
		else
			ft_check_path(params, argv[i]);
		i++;
	}
}

void		ft_init(t_parameters *params, char **envp)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		params->parameters[i] = 0;
		i++;
	}
	params->paths = NULL;
	ft_get_pwd(params, envp);
}

int			main(int argc, char **argv, char **envp)
{
	t_parameters	params;

	ft_init(&params, envp);
	if (argc > 1)
		ft_set_parameters(argc, argv, &params);
	printf("%d, %d, %d, %d, %d\n", params.parameters[0],
			params.parameters[1], params.parameters[2], params.parameters[3],
			params.parameters[4]);
	while (params.paths)
	{
		printf("PATH= %s\n",params.paths->path);
		params.paths = params.paths->next;
	}
	return (0);
}
