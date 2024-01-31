#include "cub3d.h"

char	**convert_lst_to_char(t_list *lst)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!str)
		error_msg("Error: Memory str[][]", NULL);
	while (lst)
	{
		str[i] = ft_strdup(lst->content);
		if (!str[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
	return (str);
}

bool	vaild_map_char(char c)
{
	if (c != ' ' && c != '\n')
		return (true);
	return (false);
}
