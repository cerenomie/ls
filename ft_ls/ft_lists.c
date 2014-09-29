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
