/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:13:42 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/03/30 20:49:20 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mms/mlxbeta.h"
#include "cub.h"

int				ft_exit(t_cub *cub)
{
	int			i;

	if (cub->mlx.win)
	{
		mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	}
	i = 0;
	while (i < 5)
		ft_free((void *)&cub->tex.texture[i++]);
	free(cub->tex.texture);
	ft_free((void *)&cub->sp.zbuf);
	i = 0;
	while (i < cub->map.my)
	{
		ft_free((void *)&cub->sp.vis[i]);
		ft_free((void *)&cub->map.map[i]);
		i++;
	}
	free(cub->sp.vis);
	free(cub->map.map);
	for (;;)
	;
	exit(0);
	return (0);
}

void			ft_screen(t_cub *cub)
{
	int			sx;
	int			sy;

	mlx_get_screen_size(cub->mlx.mlx, &sx, &sy);
	if (cub->map.r[0] > sx || cub->map.r[1] > sy)
	{
		cub->map.r[0] = sx;
		cub->map.r[1] = sy;
	}
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->map.r[0], cub->map.r[1], "cub3D");
	cub->img.img = mlx_new_image(cub->mlx.mlx, cub->map.r[0], cub->map.r[1]);
}