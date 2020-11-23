/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:48:57 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/11/23 20:00:56 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_chage_base(char *ptr)
{
	char	c;
	int		i;

	i = -1;
	while (++i < 10)
		ptr[i] = i + 48;
	c = 'A';
	while (c < 'G')
		ptr[i++] = c++;
	return (ptr);
}

int			len_of_index(unsigned int nbr, int base_len)
{
	int		i;

	i = 0;
	while (nbr /= base_len)
		i++;
	return (i);
}

void		digits_to_base(unsigned int nbr, char *base, int base_len, int last_index)
{
	char	result_arr[16];
	int		i;
	int		j;

	i = 0;
	j = last_index;
	while (last_index >= 0)
	{
		result_arr[last_index] = base[nbr % base_len];
		nbr /= base_len;
		last_index--;
	}
	while (i <= j)
	{
		write(1, &result_arr[i++], 1);
		count++;
	}
}

void				ft_putnbr_base(unsigned int nbr, char *base, char fm)
{
	unsigned int	base_len;
	unsigned int	last_index;
	char			*ptr;

	base_len = 16;
	if (fm == 'X')
	{
		if (!(ptr = malloc(sizeof(char) * (base_len + 1))))
			return ;
		ptr[16] = 0;
		base = ft_chage_base(ptr);
		free(ptr);
	}
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		count++;
	}
	else
	{
		last_index = len_of_index(nbr, base_len);
		digits_to_base(nbr, base, base_len, last_index);
	}
}