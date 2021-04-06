/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:33:01 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/08 17:54:38 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_print_zero(int i)
{
	while (i > 0 && i != 0)
	{
		ft_putchar_fd('0', 1);
		i--;
	}
	g_lst.iszero = 0;
	return (i);
}