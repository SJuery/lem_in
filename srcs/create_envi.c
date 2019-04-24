/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_envi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:58:03 by sjuery            #+#    #+#             */
/*   Updated: 2018/02/06 07:06:23 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				list_len(t_roomlist *beginlist)
{
	t_roomlist		*node;
	int				i;

	i = 0;
	node = beginlist;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void			create_room(t_roomlist **beginlist, t_rooms *rm)
{
	t_roomlist	*tmp;
	t_roomlist	*node;

	node = ft_memalloc(sizeof(t_roomlist));
	if (node)
		node->room = rm;
	tmp = *beginlist;
	if (!tmp)
		*beginlist = node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

static void		create_tube(t_lemin *lmn, t_roomlist **beginlist)
{
	t_roomlist	*tmp;
	t_roomlist	*node;

	node = ft_memalloc(sizeof(t_roomlist));
	if (node)
	{
		tmp = lmn->rooms;
		while (tmp)
		{
			if (!ft_strcmp(lmn->tube_data[0], tmp->room->name))
				node->room = tmp->room;
			if (!ft_strcmp(lmn->tube_data[1], tmp->room->name))
				node->s_room = tmp->room;
			tmp = tmp->next;
		}
	}
	tmp = *beginlist;
	if (tmp == NULL)
		*beginlist = node;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void			sort_rooms(t_lemin *lmn)
{
	t_rooms		*rm;

	rm = ft_memalloc(sizeof(t_rooms));
	rm->name = lmn->room_data[0];
	rm->cd.x = ft_atoi(lmn->room_data[1]);
	rm->cd.y = ft_atoi(lmn->room_data[2]);
	rm->weight = -1;
	if (!ft_strcmp("##start", lmn->prev))
	{
		lmn->cnt++;
		rm->ant = lmn->number_ant;
		rm->state = room_start;
	}
	else if (!ft_strcmp("##end", lmn->prev))
	{
		lmn->cnt++;
		rm->state = room_end;
	}
	create_room(&(lmn->rooms), rm);
}

void			sort_tubes(t_lemin *lmn)
{
	t_roomlist		*tmp;
	int				cnt;

	cnt = 0;
	tmp = lmn->rooms;
	while (tmp)
	{
		if (!ft_strcmp(lmn->tube_data[0], tmp->room->name))
			cnt++;
		if (!ft_strcmp(lmn->tube_data[1], tmp->room->name))
			cnt++;
		tmp = tmp->next;
	}
	if (cnt == 2)
		create_tube(lmn, &(lmn->tubes));
	else
		handle_error("ERROR WITH TUBES: CHECK INPUT\n", lmn);
}
