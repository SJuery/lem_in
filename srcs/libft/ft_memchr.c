/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:28:21 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/21 12:29:40 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *tsrc;

	tsrc = (unsigned char*)src;
	while (len > 0 && *tsrc != (unsigned char)c)
	{
		len--;
		tsrc++;
	}
	if (len == 0)
		return (NULL);
	else
		return (tsrc);
}
