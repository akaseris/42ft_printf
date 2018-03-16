/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:35:56 by akaseris          #+#    #+#             */
/*   Updated: 2018/03/04 20:19:19 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handledi(t_print *sprint, va_list ap)
{
	if (ft_strstr(sprint->size, "ll"))
		ft_longlong(sprint, ap);
	else if (ft_strchr(sprint->size, 'l'))
		ft_long(sprint, ap);
	else if (ft_strstr(sprint->size, "hh"))
		ft_schar(sprint, ap);
	else if (ft_strchr(sprint->size, 'z'))
		ft_size_t(sprint, ap);
	else if (ft_strchr(sprint->size, 'j'))
		ft_intmax_t(sprint, ap);
	else if (ft_strchr(sprint->size, 'h'))
		ft_short(sprint, ap);
	else
		ft_int(sprint, ap);
}

void	ft_handleoux(t_print *sprint, va_list ap)
{
	if (sprint->type == 'p')
		ft_pointer(sprint, ap);
	else if (ft_strstr(sprint->size, "ll"))
		ft_ulonglong(sprint, ap);
	else if (ft_strchr(sprint->size, 'l'))
		ft_ulong(sprint, ap);
	else if (ft_strstr(sprint->size, "hh"))
		ft_uchar(sprint, ap);
	else if (ft_strchr(sprint->size, 'h'))
		ft_ushort(sprint, ap);
	else if (ft_strchr(sprint->size, 'j'))
		ft_uintmax_t(sprint, ap);
	else if (ft_strchr(sprint->size, 'z'))
		ft_usize_t(sprint, ap);
	else
		ft_uint(sprint, ap);
}
