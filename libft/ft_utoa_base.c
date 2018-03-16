/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:57:18 by akaseris          #+#    #+#             */
/*   Updated: 2018/03/04 20:08:49 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_addchar(char *str, int nb)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	while (str[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(*str) * (i + 2));
	i = 0;
	str[i] = (nb > 9) ? nb + 55 : nb + 48;
	while (tmp[i] != '\0')
	{
		str[i + 1] = tmp[i];
		i++;
	}
	str[i + 1] = '\0';
	free(tmp);
	return (str);
}

char		*ft_utoa_base(uintmax_t val, int base)
{
	char		*str;

	if (base < 2 || base > 16)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * 1);
	str[0] = '\0';
	while (val / base > 0)
	{
		str = ft_addchar(str, val % base);
		val = val / base;
	}
	str = ft_addchar(str, val);
	return (str);
}
