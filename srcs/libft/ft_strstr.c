/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:42:01 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/21 15:48:13 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	char *tstr1;
	char *tstr2;

	if (!*str2)
		return ((char *)str1);
	while (*str1)
	{
		tstr1 = (char *)str1;
		tstr2 = (char *)str2;
		while (*tstr2 && *tstr1 == *tstr2)
		{
			tstr1++;
			tstr2++;
		}
		if (!*tstr2)
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
