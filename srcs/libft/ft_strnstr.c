/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:48:14 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/24 18:53:18 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	unsigned int i;
	unsigned int j;

	if (*str2 == '\0')
		return ((char *)str1);
	i = 0;
	while (str1[i] && i < n)
	{
		j = 0;
		while (str1[i + j] && i + j < n && str2[j] && str1[i + j] == str2[j])
			j++;
		if (str2[j] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (NULL);
}
