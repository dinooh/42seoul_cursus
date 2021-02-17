/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:09:10 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/11 18:04:46 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	else
		len = ft_strlen(s1);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr[len] = 0;
	i = 0;
	while (len--)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	return (ptr);
}
