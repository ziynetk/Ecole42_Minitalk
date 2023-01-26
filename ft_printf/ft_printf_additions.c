/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_additions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkusasla <zkusasla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:36:41 by zkusasla          #+#    #+#             */
/*   Updated: 2023/01/15 04:36:43 by zkusasla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_abs(int content)
{
	if (content < 0)
	{
		ft_putchar('-');
		if (content == -2147483648)
			return (ft_convert(2147483648, "0123456789") + 1);
		content *= -1;
		return (ft_convert(content, "0123456789") + 1);
	}
	return (ft_convert(content, "0123456789"));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *c)
{
	if (!c)
		return (ft_putstr("(null)"));
	return (write(1, c, ft_strlen(c)));
}

int	ft_convert(size_t data, char *base)
{	
	int			len;
	char		*ptr;
	char		str[20];

	len = ft_strlen(base);
	ptr = &str[19];
	*ptr = '\0';
	*--ptr = base[data % len];
	data = data / len;
	while (data != 0)
	{
		*--ptr = base[data % len];
		data = data / len;
	}
	return (ft_putstr(ptr));
}
