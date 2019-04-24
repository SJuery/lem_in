/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:20:54 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/24 20:34:58 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlink;

	nlink = (t_list*)malloc(sizeof(t_list));
	if (!nlink)
		return (NULL);
	if (!content)
	{
		nlink->content = NULL;
		nlink->content_size = 0;
	}
	else
	{
		nlink->content = malloc(content_size);
		if (!content)
		{
			free(nlink);
			return (NULL);
		}
		ft_memcpy(nlink->content, content, content_size);
		nlink->content_size = content_size;
	}
	nlink->next = NULL;
	return (nlink);
}
