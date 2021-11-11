#include "so_long.h"
static t_assets	key_move(t_assets assets, int keycode);

int	ft_close(int keycode, t_assets *assets)
{
	(void)assets;
	exit(0);
	return (keycode);
}

int	key_hook(int keycode, t_assets *assets)
{
	*assets = key_move(*assets, keycode);
	*assets = ft_move(*assets);
	return (0);
}

static t_assets	key_move(t_assets assets, int keycode)
{
	assets.player_move_x = 0;
	assets.player_move_y = 0;
	if (keycode == ESC)
		exit(0);
	else if (keycode == D)
	{
		assets.player_move_x = 1;
		assets.player = assets.player_right;
	}
	else if (keycode == A)
	{
		assets.player_move_x = -1;
		assets.player = assets.player_left;
	}
	else if (keycode == W)
	{
		assets.player_move_y = -1;
		assets.player = assets.player_up;
	}
	else if (keycode == S)
	{
		assets.player_move_y = 1;
		assets.player = assets.player_down;
	}
	return (assets);
}
