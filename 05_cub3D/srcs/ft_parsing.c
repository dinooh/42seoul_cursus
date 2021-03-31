#include "cub.h"

void				map_init(t_cub *cub)
{
	int				idx;
	int				jdx;
	int				kdx;
	int				tab;

	cub->map.map = (int **)malloc(sizeof(int *) * cub->map.my);
	cub->map.mx++;
	idx = 0;
	kdx = 0;
	while (idx < cub->map.my)
	{
		cub->map.map[idx] = (int *)malloc(sizeof(int) * (cub->map.mx));
		jdx = 0;
		while (jdx < cub->map.mx)
		{
			if (cub->map.parsed_map[kdx] == '\n')
			{
				while (jdx < cub->map.mx)
				{
					cub->map.map[idx][jdx] = 8;
					jdx++;
				}
			}
			else if (cub->map.parsed_map[kdx] == '0' || cub->map.parsed_map[kdx] == '1' || \
			cub->map.parsed_map[kdx] == '2')
				cub->map.map[idx][jdx] = cub->map.parsed_map[kdx] - '0';
			else if (is_player(cub, cub->map.parsed_map[kdx]))
				cub->map.map[idx][jdx] = cub->map.parsed_map[kdx];
			else if (cub->map.parsed_map[kdx] == '\t')
			{
				tab = 4;
				while (tab--)
				{
					cub->map.map[idx][jdx] = 8;
					jdx++;
				}
				jdx--;
			}
			else
				cub->map.map[idx][jdx] = 8;
			jdx++;
			kdx++;
		}
		idx++;
	}
}

void				get_map(t_cub *cub, int idx)
{
	char			*room;

	room = ft_strjoin(cub->map.buf[idx], "\n");
	free(cub->map.buf[idx]);
	cub->map.buf[idx] = ft_strdup(room);
	free(room);
	if (cub->map.my == 0)
	{
		cub->map.mx = ft_strlen(cub->map.buf[idx]);
		cub->map.parsed_map = ft_strdup(cub->map.buf[idx]);
	}
	else
	{
		if (cub->map.mx < ft_strlen(cub->map.buf[idx]))
			cub->map.mx = ft_strlen(cub->map.buf[idx]);
		room = ft_strjoin(cub->map.parsed_map, cub->map.buf[idx]);
		free(cub->map.parsed_map);
		cub->map.parsed_map = ft_strdup(room);
		free(room);
	}
	free(cub->map.buf[idx]);
}

void				get_route(t_cub *cub, int idx, int jdx)
{
	char			*ptr;
	int				s;
	int				end;

	end = jdx + 2;
	while (is_space(cub->map.buf[idx][end]))
		end++;
	s = end;
	while (cub->map.buf[idx][end] >= 33 && cub->map.buf[idx][end] <= 126)
		end++;
	ptr = ft_substr(cub->map.buf[idx], s, end);
	if (cub->map.buf[idx][jdx] == 'E')
		cub->map.ea = ft_strdup(ptr);
	else if (cub->map.buf[idx][jdx] == 'N')
		cub->map.no = ft_strdup(ptr);
	else if (cub->map.buf[idx][jdx] == 'W')
		cub->map.we = ft_strdup(ptr);
	else if (cub->map.buf[idx][jdx] == 'S' && \
	cub->map.buf[idx][1] == 'O')
		cub->map.so = ft_strdup(ptr);
	else if (cub->map.buf[idx][jdx] == 'S' && \
	cub->map.buf[idx][1] != 'O')
		cub->map.s = ft_strdup(ptr);
	free(ptr);
}

void				get_numdata(t_cub *cub, int idx, int jdx, int loop)
{
	char			*ptr;
	int				x;
	int				start;
	int				end;

	x = 0;
	end = jdx;
	while (x < loop)
	{
		while (!(cub->map.buf[idx][end] >= '0' && \
					cub->map.buf[idx][end] <= '9'))
			end++;
		start = end;
		while (cub->map.buf[idx][end] >= '0' && \
				cub->map.buf[idx][end] <= '9')
			end++;
		ptr = ft_substr(cub->map.buf[idx], start, end);
		if (cub->map.buf[idx][jdx] == 'R')
			cub->map.r[x] = ft_atoi(ptr);
		else if (cub->map.buf[idx][jdx] == 'C')
			cub->map.c[x] = ft_atoi(ptr);
		else if (cub->map.buf[idx][jdx] == 'F')
			cub->map.f[x] = ft_atoi(ptr);
		free(ptr);
		x++;
	}
}

void				get_data(t_cub *cub, int idx, int jdx)
{
	if (cub->map.buf[idx][jdx] == 'R')
	{
		cub->map.r = (int *)malloc(sizeof(int) * 2);
		get_numdata(cub, idx, jdx, 2);
	}
	else if (cub->map.buf[idx][jdx] == 'C' || cub->map.buf[idx][jdx] == 'F')
	{
		if (cub->map.buf[idx][jdx] == 'C')
			cub->map.c = (int *)malloc(sizeof(int) * 3);
		else if (cub->map.buf[idx][jdx] == 'F')
			cub->map.f = (int *)malloc(sizeof(int) * 3);
		get_numdata(cub, idx, jdx, 3);
	}
	else
		get_route(cub, idx, jdx);
	free(cub->map.buf[idx]);
}

void				ft_parsing(t_cub *cub)
{
	int				idx;
	int				jdx;
	int				is_read;
	int				fd;

	cub->map.buf = (char **)malloc(sizeof(char *) * 10);
	cub->map.mx = 0;
	cub->map.my = 0;
	fd = open("cub.map", O_RDONLY);
	idx = 0;
	is_read = fd;
	while (is_read)
	{
		is_read = get_next_line(fd, &cub->map.buf[idx]);
		jdx = except_space(cub, idx);
		if (jdx != -1 && cub->map.buf[idx])
		{
			if (idx < 8)
			{
				get_data(cub, idx, jdx);
				idx++;
			}
			else if (idx == 8)
			{
				get_map(cub, idx);
				cub->map.my++;
			}
		}
	}
	free(cub->map.buf);
	cub->map.buf = NULL;
	close(fd);
	map_init(cub);
	printf("%d %d\n", cub->map.my, cub->map.mx);
	printf("#####\nPARSED MAP\n#####\n%s", cub->map.parsed_map);
	printf("#####\nMAP\n#####\n");
	for (int i = 0; i < cub->map.my; i++)
	{
		for (int j = 0; j < cub->map.mx; j++)
		{
			if (cub->map.map[i][j] >= 'A')
				printf("%c ", cub->map.map[i][j]);
			else
				printf("%d ", cub->map.map[i][j]);
		}
		printf("\n");
	}
	free(cub->map.parsed_map);
}