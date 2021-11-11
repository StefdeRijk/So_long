#include "so_long.h"
static void	check_argument(t_assets assets);

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

static void	check_argument(t_assets assets)
{
	char	*str;
	int		len;

	str = assets.argument;
	len = ft_strlen(str) - 1;
	if (str[len] == 'r')
	{
		len--;
		if (str[len] == 'e')
		{
			len--;
			if (str[len] == 'b')
			{
				len--;
				if (str[len] == '.')
					return ;
			}
		}
	}
	ft_error(assets, "Error\nInvalid map file");
}

void	ft_error(t_assets assets, char *str)
{
	assets.error_message = str;
	printf("%s", assets.error_message);
	free(assets.map);
	exit(0);
	return ;
}
