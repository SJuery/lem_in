/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:23:53 by sjuery            #+#    #+#             */
/*   Updated: 2017/11/05 04:00:16 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *new;

	new = ft_strnew(ft_strlen(s1));
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
