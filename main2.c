#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	handle_close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path = "./woods.xpm";
	int		img_width;
	int		img_height;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "My Window");
	img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);

	// Calculate the number of times to repeat the texture
	int repeat_x = 800 / img_width + 1;
	int repeat_y = 600 / img_height + 1;

	// Loop to put the texture in each position
	int x = 0;
	int y = 0;
	while (y < repeat_y) {
		mlx_put_image_to_window(vars.mlx, vars.win, img, x * img_width, y * img_height);
		x++;
		if (x >= repeat_x) {
			x = 0;
			y++;
		}
	}

	mlx_hook(vars.win, 2, 1L<<0, handle_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
