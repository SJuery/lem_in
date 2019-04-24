/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:32:53 by sjuery            #+#    #+#             */
/*   Updated: 2018/02/06 04:24:26 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;

	m = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (m == NULL)
		return (m);
	ft_strcpy(m, s1);
	ft_strcat(m, s2);
	return (m);
}
