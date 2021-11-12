#include "so_long.h"
void	check_argument(t_assets assets)
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
	ft_error(assets, "Error\nArgument is not a .ber file");
}

void	ft_error(t_assets assets, char *str)
{
	assets.error_message = str;
	printf("%s", assets.error_message);
	free(assets.map);
	mlx_destroy_window(assets.mlx, assets.win);
	exit(0);
	return ;
}
