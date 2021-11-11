#include "so_long.h"
static t_assets	ft_move2(t_assets assets, int new_x, int new_y);

static t_assets	ft_move3(t_assets assets, int new_x, int new_y);

t_assets	ft_move(t_assets assets)
{
	int	new_x;
	int	new_y;

	new_x = assets.player_x + assets.player_move_x;
	new_y = assets.player_y + assets.player_move_y;
	if (assets.player_move_x != 0 || assets.player_move_y != 0)
	{
		if (assets.map[new_y][new_x] != '1')
			assets = ft_move2(assets, new_x, new_y);
		if (assets.collectables == 0)
		{
			assets.exit = assets.exit_green;
			assets.end_access = 1;
		}
		assets = ft_paint_window(assets);
	}
	return (assets);
}

static t_assets	ft_move2(t_assets assets, int new_x, int new_y)
{
	if (assets.end_access == 0)
	{
		if (assets.map[new_y][new_x] == 'E')
			return (assets);
		if (assets.map[new_y][new_x] == 'C')
			assets.collectables -= 1;
		if (assets.map[new_y][new_x] == 'S')
			ft_error(assets, "You lost\n");
		assets.map[assets.player_y][assets.player_x] = '0';
		assets.map[new_y][new_x] = 'P';
	}
	else
		ft_move3(assets, new_x, new_y);
	assets.moves += 1;
	printf("The current number of moves = %i\n", assets.moves);
	return (assets);
}

static t_assets	ft_move3(t_assets assets, int new_x, int new_y)
{
	if (assets.map[new_y][new_x] == 'E')
	{
		assets.moves += 1;
		printf("The current number of moves = %i\n", assets.moves);
		printf("%s", "You won!\n");
		ft_close(0, &assets);
	}
	if (assets.map[new_y][new_x] == 'S')
		ft_error(assets, "You lost\n");
	assets.map[assets.player_y][assets.player_x] = '0';
	assets.map[new_y][new_x] = 'P';
	return (assets);
}
