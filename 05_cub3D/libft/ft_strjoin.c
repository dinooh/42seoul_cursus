/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:41:19 by jeunjeon          #+#    #+#             */
/*   Updated: 2020/12/11 18:05:38 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	else
	{
		ft_strlcpy(ptr, (char *)s1, len1 + 1);
		ft_strlcat(ptr, (char *)s2, len1 + len2 + 1);
	}
	return (ptr);
}
