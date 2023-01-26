/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkusasla <zkusasla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:36:26 by zkusasla          #+#    #+#             */
/*   Updated: 2023/01/15 04:36:32 by zkusasla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		temp;
	int		len;

	len = 1;
	temp = n;
	while (temp && len++)
		temp /= 10;
	str = malloc(sizeof(char) * ((n < 0) + len + (n == 0)));
	if (!str)
		return (NULL);
	str += (n < 0) + (len - 1) + (n == 0);
	*str = '\0';
	if (n == 0)
		*(--str) = '0';
	len = (n >= 0) * 2 - 1;
	while (n)
	{
		*(--str) = (n % (10 * len)) * len + '0';
		n /= 10;
	}
	if (len < 0)
		*(--str) = '-';
	return (str);
}
