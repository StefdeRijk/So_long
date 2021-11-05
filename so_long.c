#include "so_long.h"
#include "mlx.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		key_hook(int keycode, t_data img);

int	main(void)
{
	t_data			img;
	t_vars			vars;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Ziek spelletje");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	while (y < 1080)
	{
		my_mlx_pixel_put(&img, x, y, 0xAF00FF00);
		x++;
		if (x == 1920)
		{
			y++;
			x = 0;
		}
	}
	mlx_key_hook(vars.win, key_hook, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_data img)
{
	unsigned int	x;
	unsigned int	y;

	y = 100;
	x = 100;
	keycode = 0;
	while (y < 980)
	{
		my_mlx_pixel_put(&img, x, y, 0x7FFF0000);
		x++;
		if (x == 1820)
		{
			y++;
			x = 100;
		}
	}
	return (0);
}
