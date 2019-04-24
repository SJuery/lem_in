/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:42:01 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/21 14:07:07 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *last_oc;

	last_oc = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last_oc = (char *)str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (last_oc);
}
