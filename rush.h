#ifndef RUSH_H
# define RUSH_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_rush
{
    int **res; //n * n
    int **row; //n * (n + 1)
    int **col; //n * (n + 1)
    int *visible; //4
    int *data; //4
}   t_rush;

typedef struct  s_idx
{
    int size; //n
    int *left; //n
    int *right; //n
    int *up; //n
    int *down; //n
}   t_idx;


int	ft_check_valid_num(char *str, int n);
void	ft_copy_table(char *str, t_rush *data);
int	ft_erase_blank(char *str);
int	error_check(char *str);
void    ft_free_data(t_rush *data, int size);
void    ft_free_idx(t_idx *idx);
void    ft_init_data(t_rush *rush_data, int size, char *str);
void    ft_init_idx(t_idx *rush_idx, int size);
int	ft_isdigit(int c);
int	ft_isvalid_coldown(int row, int *dif, t_rush *data, t_idx *idx);
int	ft_isvalid_colup(int row, int *dif, t_rush *data, t_idx *idx);
int	ft_isvalid_rowleft(int row, int *dif, t_rush *data, t_idx *idx);
int	ft_isvalid_rowright(int row, int *dif, t_rush *data, t_idx *idx);
void	ft_is_valid(int row, int *dif, t_rush *data, t_idx *idx);
void    ft_post_rush(int num, int *dif, t_rush *data, t_idx *idx);
void    ft_pre_rush_col(int *dif, t_rush *data, t_idx *idx);
void    ft_pre_rush_row(int *dif, t_rush *data, t_idx *idx);
void    ft_pre_rush(int num, int *dif, t_rush *data, t_idx *idx);
void	ft_print(int **res, int size);
void	ft_putstr(char *str);
void	ft_reset_data(t_rush *rush_data, int size);
void    ft_reset_idx(t_idx *rush_idx, int size);
void	ft_rush(t_rush *data, t_idx *idx, int size);
int	ft_solve_rush(int num, int col, t_rush *data, t_idx *idx);
int	ft_strlen(char *str);



#endif