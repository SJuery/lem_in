/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 04:53:13 by sjuery            #+#    #+#             */
/*   Updated: 2018/02/06 11:34:06 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct s_rooms		t_rooms;
typedef struct s_roomlist	t_roomlist;

enum						e_state { ant_count, parse_map,
	room_start, room_end };

typedef struct				s_points
{
	int						x;
	int						y;
}							t_points;

struct						s_rooms
{
	char					*name;
	enum e_state			state;
	t_points				cd;
	int						weight;
	int						ant;
	t_roomlist				*linkrooms;
};

struct						s_roomlist
{
	t_rooms					*room;
	t_rooms					*s_room;
	t_roomlist				*next;
};

typedef struct				s_lemin
{
	int						number_ant;
	int						cnt;
	enum e_state			state;
	char					*links;
	char					*line;
	char					*prev;
	t_roomlist				*rooms;
	char					**room_data;
	t_roomlist				*tubes;
	char					**tube_data;
	t_rooms					*room_start;
	t_rooms					*room_end;
}							t_lemin;

void						sort_rooms(t_lemin *lmn);
void						sort_tubes(t_lemin *l);
void						create_room(t_roomlist **beginlist, t_rooms *rm);
int							list_len(t_roomlist *beginlist);
void						parse_stdout(t_lemin *l);
void						handle_error(char *error_type, t_lemin *lmn);
void						lemin(t_lemin *lmn);
void						algorithm(t_lemin *lmn);

#endif
