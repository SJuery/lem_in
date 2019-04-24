/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:44:23 by sjuery            #+#    #+#             */
/*   Updated: 2017/12/03 06:18:43 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr(unsigned long long int n)
{
	if (n > ULLONG_MAX)
		return ;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
}
