/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_so_long.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrevess <egrevess@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:14 by egrevess          #+#    #+#             */
/*   Updated: 2023/04/11 11:30:46 by egrevess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SO_LONG_H
# define LIB_SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_vars
{
	char	*src;
	int		compt;
	int		len_row;
	int		len_col;
	int		position_y_p;
	int		position_x_p;
	char	**tab;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	void	*img_wall;
	void	*img_position;
	void	*img_end;
	void	*img_items;
	void	*img_void;
	void	*img_white;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		posx;
	int		posy;
	char	**tab_check;
}				t_vars;

enum
{
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_ESC = 53,
	KEY_PLUS = 24,
	KEY_MINUS = 27,
	KEY_UP = 126,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_0 = 82,
	KEY_1 = 83,
	KEY_2 = 84,
	KEY_3 = 85,
	KEY_4 = 86,
	KEY_5 = 87,
	KEY_6 = 88,
	KEY_7 = 89,
	KEY_8 = 91,
	KEY_9 = 92,
	KEY_PLUS_PAD = 69,
	KEY_MINUS_PAD = 78
};

void	check_len(char *line, int i);
int		f_strlen(const char *s);
char	*f_strcat(char *src, char **line);
void	check_map(t_vars *var);
int		nb_nl(char *src);
char	**make_tab(t_vars *var);
char	**put_in_tab(char **res, t_vars *var);
int		nb_betweeen_nl(char *src);
void	ft_swap_up(t_vars *var);
void	ft_swap_down(t_vars *var);
void	ft_swap_left(t_vars *var);
void	ft_swap_right(t_vars *var);
void	ft_init_position(t_vars *var);
void	ft_init_tab(t_vars *var);
void	ft_putstring(char *str);
int		ft_close(t_vars *var);
void	ft_init_mlx(t_vars *var);
int		key_hook(int keycode, t_vars *var);
int		check_win(t_vars *var);
char	*free_tab(t_vars *var);
char	*free_tab_check(t_vars *var);
int		check_valid_path(t_vars *var);
void	ft_init_position_check(t_vars *var);
int		check_position(t_vars *var);
void	ft_error(void);
void	ft_perror(const char *str);
int		check_exit(t_vars *var);
int		check_enter(t_vars *var);
void	ft_print_compt(t_vars *var);
#endif
