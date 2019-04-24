/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 16:44:28 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/24 17:49:47 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;
	size_t	j;

	j = ft_numcount(n);
	if (!(dst = ft_strnew(j)))
		return (NULL);
	if (n == 0)
	{
		dst[0] = 48;
		return (dst);
	}
	if (n < 0)
		dst[0] = '-';
	while (j - 1 > 0)
	{
		i = n % 10;
		if (i < 0)
			i = -i;
		dst[j-- - 1] = i + 48;
		n /= 10;
	}
	if (n > 0)
		dst[0] = n + 48;
	return (dst);
}
