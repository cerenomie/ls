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
	t_list					*paths;
}							t_parameters;


t_list						*add_link(t_list *list, char *data);
#endif
