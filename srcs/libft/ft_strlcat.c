/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:52:25 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/25 17:09:09 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	unsigned int tlen;

	tlen = ft_strlen(src) + ft_strlen(dst);
	if (len > ft_strlen(dst))
	{
		ft_strncat(dst, src, len - ft_strlen(dst) - 1);
		return (tlen);
	}
	return (len + ft_strlen(src));
}
