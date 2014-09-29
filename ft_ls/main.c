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

void		set_parameters(int argc, char **argv, t_parameters *params)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && i == 1)
			get_parameters_type(argv[i], params->parameters);
		else
			params->paths = add_link(params->paths, argv[i]);
		i++;
	}
}

void		check_parameters(int argc, char **argv, t_parameters *params)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		params->parameters[i] = 0;
		i++;
	}
	if (argc > 1)
	{
		set_parameters(argc, argv, params);
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_parameters	params;

	(void)envp;
	check_parameters(argc, argv, &params);
	while (params.paths)
	{
		printf("PATH=%s\n", params.paths->path);
		params.paths = params.paths->next;
	}
	return (0);
}
