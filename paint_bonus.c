#include "so_long_bonus.h"
static t_assets	ft_paint_asset(t_assets assets, char c, int x, int y);

t_assets	ft_paint_window(t_assets assets)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < assets.screen_height / 32)
	{
		while (x < assets.screen_width / 32)
		{
			assets = ft_paint_asset(assets, assets.map[y][x], x, y);
			x++;
		}
		y++;
		x = 0;
	}
	return (assets);
}

static t_assets	ft_paint_asset(t_assets assets, char c, int x, int y)
{
	mlx_put_image_to_window(assets.mlx, assets.win, \
	assets.grass, x * 32, y * 32);
	if (c == '1')
		mlx_put_image_to_window(assets.mlx, assets.win, \
		assets.rock, x * 32, y * 32);
	if (c == 'P')
	{
		mlx_put_image_to_window(assets.mlx, assets.win, \
		assets.player, x * 32, y * 32);
		assets.player_x = x;
		assets.player_y = y;
	}
	if (c == 'C')
		mlx_put_image_to_window(assets.mlx, assets.win, \
		assets.heart, x * 32, y * 32);
	if (c == 'E')
		mlx_put_image_to_window(assets.mlx, assets.win, \
		assets.exit, x * 32, y * 32);
	if (c == 'S')
		mlx_put_image_to_window(assets.mlx, assets.win, \
		assets.skeleton, x * 32, y * 32);
	return (assets);
}
