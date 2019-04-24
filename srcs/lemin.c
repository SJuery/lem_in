/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:08:57 by sjuery            #+#    #+#             */
/*   Updated: 2018/02/06 11:27:51 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			handle_error(char *error_type, t_lemin *lmn)
{
	ft_putstr(error_type);
	ft_putstr(lmn->line);
	if(lmn->line)
		ft_putstr("\n");
	exit(0);
}

static void		free_info(t_lemin *lmn, char type)
{
	char *tmp;
	char *tmp2;

	if (lmn->room_data && type == 'r')
	{
		free(lmn->room_data[1]);
		free(lmn->room_data[2]);
		free(lmn->room_data);
	}
	if (lmn->tube_data && type == 't')
	{
		free(lmn->tube_data[0]);
		free(lmn->tube_data[1]);
		free(lmn->tube_data);
	}
	if (type == 'm')
	{
		tmp2 = ft_strjoin(lmn->line, "\n");
		tmp = ft_strjoin(lmn->links, tmp2);
		if (tmp2)
			free(tmp2);
		if (lmn->links)
			free(lmn->links);
		lmn->links = tmp;
	}
}

static int		validate_info(t_lemin *lmn)
{
	int i;

	i = 0;
	if (ft_strchr(lmn->line, ' '))
	{
		free_info(lmn, 'r');
		lmn->room_data = ft_strsplit(lmn->line, ' ');
		if (lmn->room_data[0][0] != 'L' && ft_isnumber(lmn->room_data[1])
			&& ft_isnumber(lmn->room_data[2]) && !lmn->room_data[3])
		{
			while (lmn->room_data[0][i] != '-' && lmn->room_data[0][i])
				i++;
			return ((i != ft_strlen(lmn->room_data[0])) ? 0 : 1);
		}
	}
	else if (ft_strchr(lmn->line, '-'))
	{
		free_info(lmn, 't');
		lmn->tube_data = ft_strsplit(lmn->line, '-');
		if (lmn->tube_data[0] && lmn->tube_data[1]
			&& !lmn->tube_data[2])
			return (2);
	}
	return (0);
}

static void		parse_input(t_lemin *lmn)
{
	if (lmn->state == ant_count)
	{
		if (!ft_isnumber(lmn->line))
			handle_error("ERROR WITH ANTS: CHECK INPUT\n", lmn);
		else
			lmn->number_ant = ft_atoi(lmn->line);
		lmn->state = parse_map;
	}
	else if (lmn->state == parse_map)
	{
		if (validate_info(lmn) == 1)
			sort_rooms(lmn);
		else if (validate_info(lmn) == 2)
			sort_tubes(lmn);
		else
			handle_error("ERROR WITH TUBES: CHECK INPUT\n", lmn);
	}
}

int				main(int nbr, char **stuff)
{
	t_lemin			*lmn;

	if (nbr != 1)
		handle_error("Usage: ./lem-in < maps\n", lmn);
	lmn = ft_memalloc(sizeof(t_lemin));
	lmn->links = ft_strnew(0);
	while (get_next_line(0, &lmn->line))
	{
		if (lmn->line[0] != '#' && lmn->line[0])
			parse_input(lmn);
		free(lmn->prev);
		lmn->prev = lmn->line;
		free_info(lmn, 'm');
		if (!lmn->line[0])
			break ;
	}
	if (lmn->prev && lmn->cnt == 2)
	{
		algorithm(lmn);
		lemin(lmn);
	}
	else
		handle_error("ERROR WITH ARGUMENTS: CHECK INPUT\n", lmn);
	return (1);
}
