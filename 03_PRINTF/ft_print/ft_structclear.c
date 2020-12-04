/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:56:58 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/04 16:33:32 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_structclear(void)
{
	flst.is_left = 0;
	flst.is_zero = 0;
	flst.is_minus = 0;
	flst.pre = 0;
	flst.p_wild = 0;
	flst.width = 0;
	flst.w_wild = 0;
}
