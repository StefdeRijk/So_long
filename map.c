#include "so_long.h"
static t_assets	check_map2(t_assets assets, int i, int j);

static t_assets	check_map3(t_assets assets, int i, int j);

static t_assets	check_characters(t_assets assets, int i, int j);

t_assets	check_map(t_assets assets)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	assets.collectables = 0;
	assets.players = 0;
	assets.exits = 0;
	assets.error = 0;
	assets = check_map2(assets, i, j);
	assets = check_map3(assets, i, j);
	if (assets.collectables == 0)
		ft_error(assets, "Error\nMap doesn't have enough collectables\n");
	if (assets.exits == 0)
		ft_error(assets, "Error\nMap doesn't have enough exits\n");
	if (assets.players == 0)
		ft_error(assets, "Error\nMap doesn't have enough players\n");
	if (assets.players > 1)
		ft_error(assets, "Error\nMap has too many players\n");
	return (assets);
}

static t_assets	check_map2(t_assets assets, int i, int j)
{
	int	len;
	int	new_len;

	len = ft_strlen(assets.map[j]);
	while (j < (assets.screen_height / 32))
	{
		new_len = ft_strlen(assets.map[j]);
		while (assets.map[j][i])
		{
			if (assets.map[j][i] == 'C')
				assets.collectables += 1;
			assets = check_characters(assets, i, j);
			i++;
		}
		i = 0;
		if (len != new_len && j < (assets.screen_height / 32) - 1)
			ft_error(assets, "Error\nMap is not rectangular\n");
		if (len != new_len - 1 && j == (assets.screen_height / 32) - 1)
			ft_error(assets, "Error\nMap is not rectangular\n");
		j++;
	}
	return (assets);
}

static t_assets	check_characters(t_assets assets, int i, int j)
{
	if (assets.map[j][i] != '1' && assets.map[j][i] != '0' \
	&& assets.map[j][i] != 'P' && assets.map[j][i] != 'C' \
	&& assets.map[j][i] != 'E' && assets.map[j][i] != 'S')
		ft_error(assets, "Error\nMap has invalid characters\n");
	if (assets.map[j][i] == 'P')
		assets.players += 1;
	if (assets.map[j][i] == 'E')
		assets.exits += 1;
	return (assets);
}

static t_assets	check_map3(t_assets assets, int i, int j)
{
	int	len;

	len = ft_strlen(assets.map[j]);
	while (j < (assets.screen_height / 32))
	{
		while (assets.map[0][i] != '\0')
		{
			if (assets.map[0][i] != '1')
				ft_error(assets, "Error\nMap is not enclosed in walls\n");
			if (assets.map[(assets.screen_height / 32) - 1][i] != '1')
				ft_error(assets, "Error\nMap is not enclosed in walls\n");
			i++;
		}
		if (assets.map[j][0] != '1')
			ft_error(assets, "Error\nMap is not enclosed in walls\n");
		if (assets.map[j][(assets.screen_width / 32) - 1] != '1')
			ft_error(assets, "Error\nMap is not enclosed in walls\n");
		j++;
	}
	return (assets);
}
