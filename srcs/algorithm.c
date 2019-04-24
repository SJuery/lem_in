/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:58:51 by sjuery            #+#    #+#             */
/*   Updated: 2018/02/06 13:40:13 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			handle_weight(t_roomlist *currentlink, t_rooms *parent,
						int asign_weight)
{
	while (currentlink)
	{
		if (currentlink->room != parent &&
			currentlink->room->weight < parent->weight)
		{
			currentlink->room->weight = asign_weight;
			handle_weight(currentlink->room->linkrooms, currentlink->room,
				currentlink->room->weight - 1);
		}
		currentlink = currentlink->next;
	}
}

void				algorithm(t_lemin *lmn)
{
	t_roomlist	*tmp;

	tmp = lmn->tubes;
	while (tmp)
	{
		create_room(&(tmp->room->linkrooms), tmp->s_room);
		create_room(&(tmp->s_room->linkrooms), tmp->room);
		tmp = tmp->next;
	}
	tmp = lmn->rooms;
	while (tmp)
	{
		if (tmp->room->state == room_end)
			lmn->room_end = tmp->room;
		if (tmp->room->state == room_start)
			lmn->room_start = tmp->room;
		tmp = tmp->next;
	}
	lmn->room_end->weight = list_len(lmn->rooms);
	tmp = lmn->room_end->linkrooms;
	handle_weight(tmp, lmn->room_end, lmn->room_end->weight - 1);
	if (lmn->room_start->weight == -1)
		handle_error("ERROR WEIGHING: CHECK INPUT\n", lmn);
}

static t_rooms		*get_room(t_roomlist *current)
{
	t_roomlist		*tmp;
	t_rooms			*room_path;

	room_path = current->room;
	tmp = current->next;
	while (tmp)
	{
		if (tmp->room->weight >= room_path->weight
			&& (tmp->room->ant == 0 || tmp->room->state == room_end))
			room_path = tmp->room;
		tmp = tmp->next;
	}
	return (room_path);
}

static void			find_path(int number_ant, t_rooms **ant_rooms)
{
	int			i;
	t_rooms		*path;

	i = 0;
	while (i < number_ant)
	{
		if (ant_rooms[i]->state != room_end)
		{
			path = get_room(ant_rooms[i]->linkrooms);
			if ((path->ant == 0 && path->state != room_end)
				|| path->state == room_end)
			{
				if (ant_rooms[i]->ant > 0)
					ant_rooms[i]->ant = ant_rooms[i]->ant - 1;
				path->ant = path->ant + 1;
				ant_rooms[i] = path;
				ft_putstr("L");
				ft_putnbr(i + 1);
				ft_putstr("-");
				ft_putstr(path->name);
				ft_putstr(" ");
			}
		}
		i++;
	}
}

void				lemin(t_lemin *lmn)
{
	int			i;
	t_rooms		**ant_rooms;

	ant_rooms = ft_memalloc(sizeof(t_rooms) * lmn->number_ant);
	i = 0;
	printf("%s\n", lmn->links);
	while (i < lmn->number_ant)
	{
		ant_rooms[i] = lmn->room_start;
		i++;
	}
	while (lmn->room_end->ant != lmn->number_ant)
	{
		find_path(lmn->number_ant, ant_rooms);
		ft_putstr("\n");
		i++;
	}
	i = 0;
	free(ant_rooms);
}
