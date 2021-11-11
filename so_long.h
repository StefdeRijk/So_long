#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_assets {
	void			*player;
	void			*player_right;
	void			*player_left;
	void			*player_up;
	void			*player_down;
	void			*skeleton;
	void			*grass;
	void			*rock;
	void			*tree;
	void			*heart;
	void			*exit_red;
	void			*exit_green;
	void			*exit;

	void			*mlx;
	void			*win;

	unsigned int	player_x;
	int				player_move_x;
	unsigned int	player_y;
	int				player_move_y;

	char			*error_message;
	int				error;

	int				height;
	int				sprite_size;
	int				screen_height;
	int				screen_width;
	char			*argument;
	char			**map;

	int				collectables;
	int				moves;
	int				players;
	int				exits;
	int				end_access;
}				t_assets;

t_assets	ft_load_assets(t_assets assets);
t_assets	ft_load_game(t_assets assets);
t_assets	check_map(t_assets assets);

t_assets	ft_paint_window(t_assets assets);
t_assets	ft_move(t_assets assets);

int			key_hook(int keycode, t_assets *assets);
int			ft_close(int keycode, t_assets *assets);
void		ft_error(t_assets assets, char *str);

void		*ft_calloc(size_t count, size_t size, t_assets assets);
char		**ft_split(char const *s, char c, int *height);
int			ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);

#endif