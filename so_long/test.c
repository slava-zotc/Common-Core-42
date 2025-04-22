#include <mlx.h>
#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 2560
#define HEIGHT 1600

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_var *var)
{
	(void)var;
	if (keycode == 65307)
	{
		//mlx_destroy_display(var->mlx);
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	printf("Hello, key_kode = %d!\n", keycode);
	return (0);
}

int ft_exit(t_var *var)
{
	//mlx_destroy_display(var->mlx);
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}
int	main(void)
{
	int		bg_w, bg_h;
	t_data	img;
	t_var	var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_xpm_file_to_image(var.mlx, "test2.xpm", &bg_w, &bg_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, 17, 0, ft_exit, &var);
	mlx_loop(var.mlx);
}
