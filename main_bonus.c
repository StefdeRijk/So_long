#include "so_long_bonus.h"
int	main(int argc, char **argv)
{
	t_assets	assets;

	if (argc == 2)
	{
		assets.argument = argv[1];
		check_argument(assets);
		assets.mlx = mlx_init();
		assets.end_access = 0;
		assets.moves = 0;
		assets.sprite_size = 32;
		assets.error_message = "Error\nYou lost :(\n";
		assets = ft_load_assets(assets);
		assets = ft_load_game(assets);
		mlx_hook(assets.win, 17, 0L, ft_close, &assets);
		mlx_loop(assets.mlx);
		free(assets.map);
	}
	else
		printf("%s\n", "Error\nInvalid amount of arguments");
}
