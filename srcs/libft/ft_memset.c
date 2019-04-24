/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:23:58 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/21 17:20:57 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int val, size_t len)
{
	unsigned char *nstr;

	nstr = (unsigned char *)str;
	while (len-- > 0)
		*nstr++ = (unsigned char)val;
	return (str);
}
