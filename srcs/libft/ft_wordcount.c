/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:44:21 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/22 22:10:27 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	unsigned int	wc;
	int				i;

	i = 0;
	wc = 0;
	while (s && s[i])
	{
		while ((char)s[i] == c)
			i++;
		if (s[i] && (char)s[i] != c)
			wc++;
		while (s[i] && (char)s[i] != c)
			i++;
	}
	return (wc);
}
