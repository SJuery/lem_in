/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:26:34 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/21 11:47:11 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *tsrc;
	char *ndst;

	tsrc = (char*)src;
	ndst = (char*)dst;
	if (tsrc < ndst)
	{
		tsrc = tsrc + len - 1;
		ndst = ndst + len - 1;
		while (len > 0)
		{
			*ndst-- = *tsrc--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*ndst++ = *tsrc++;
			len--;
		}
	}
	return (dst);
}
