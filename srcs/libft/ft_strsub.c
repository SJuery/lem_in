/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:33:49 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/19 13:33:55 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (s)
	{
		if (!(new = ft_strnew(len)))
			return (NULL);
		return (ft_strncpy(new, s + start, len));
	}
	else
		return (NULL);
}
