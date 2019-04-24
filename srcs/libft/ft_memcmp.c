/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:27:17 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/21 12:32:10 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t len)
{
	unsigned char *nstr1;
	unsigned char *nstr2;

	nstr1 = (unsigned char*)str1;
	nstr2 = (unsigned char*)str2;
	while (len > 0 && *nstr1 == *nstr2)
	{
		nstr1++;
		nstr2++;
		len--;
	}
	if (len == 0)
		return (0);
	else
		return (*nstr1 - *nstr2);
}
