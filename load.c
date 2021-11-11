#include "so_long.h"
static int		ft_render_game(t_assets *assets);

static t_assets	ft_load_map(t_assets assets);

t_assets	ft_load_assets(t_assets assets)
{
	assets.player_right = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Player_right.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.player_left = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Player_left.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.player_up = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Player_up.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.player_down = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Player_down.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.grass = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Grass.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.rock = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Rock.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.heart = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Heart.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.exit_red = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Exit_inactive.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.exit_green = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Exit_active.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.skeleton = mlx_xpm_file_to_image(assets.mlx, \
	"./Assets/Skeleton.xpm", &assets.sprite_size, &assets.sprite_size);
	assets.exit = assets.exit_red;
	assets.player = assets.player_right;
	return (assets);
}

t_assets	ft_load_game(t_assets assets)
{
	assets = ft_load_map(assets);
	assets = check_map(assets);
	assets.win = mlx_new_window(assets.mlx, assets.screen_width, \
	assets.screen_height, "so_long");
	assets = ft_paint_window(assets);
	mlx_loop_hook(assets.mlx, ft_render_game, &assets);
	return (assets);
}

static t_assets	ft_load_map(t_assets assets)
{
	int		fd;
	int		read_return;
	char	*chr;
	char	*str;

	fd = open(assets.argument, O_RDONLY);
	chr = ft_calloc((2 * sizeof(char)), 1, assets);
	str = ft_calloc((1 * sizeof(char)), 1, assets);
	read_return = 1;
	while (read_return != 0)
	{
		read_return = read(fd, chr, 1);
		if (read_return == -1)
			ft_error(assets, "Error\nRead failed\n");
		str = ft_strjoin(str, chr);
	}
	free(chr);
	close(fd);
	assets.map = ft_split(str, '\n', &assets.height);
	if (!assets.map)
		ft_error(assets, "Error\nMap construction failed");
	assets.screen_width = ft_strlen(assets.map[0]) * 32;
	assets.screen_height = assets.height * 32;
	return (assets);
}

static int	ft_render_game(t_assets *assets)
{
	mlx_key_hook(assets->win, key_hook, assets);
	return (0);
}
