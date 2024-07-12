#ifndef RUSH_H
# define RUSH_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_rush
{
	int	size;
	int	**result; //n * n
	int	*col_up;
	int	*col_down;
	int	*row_left;
	int	*row_right;
	int	**row_visited;
	int	up_see[10];
	int	down_see[10];
	int	left_see[10];
	int	right_see[10];
	int	up_idx[10];
	int	down_idx[10];
	int	left_idx[10];
	int	right_idx[10];
}	t_rush;

/* main.c */
void	free_rush(t_rush **rush);

/* print.c */
void	print_result(int **arr, int size);
void	ft_putendl(char *str);

/* error.c */
void	error(int num);

/* init_validation.c */
int		isvalid_arg(char *arg, int *size);

/* init.c */
t_rush	*init_rush(int size, char *arg);
int		**init_2d(int size);

/* init_utils.c */
void	init_rush_vars(t_rush *rush);
void	free_rush(t_rush **rush);

/* solve.c */
void	rushy(t_rush *rush);

/* solve_validation.c */
int		isvalid_num(int row, int data[6], t_rush *rush);

/* solve_utils.c */
void	pre_solve(int row, int col, t_rush *rush);
void	post_solve(int row, int col, int data[6], t_rush *rush);

#endif