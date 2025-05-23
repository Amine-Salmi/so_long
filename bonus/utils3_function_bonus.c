/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_function_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 00:23:27 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 18:08:20 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	position_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->copy_map[i])
	{
		j = 0;
		while (game->copy_map[i][j])
		{
			if (game->copy_map[i][j] == 'P')
			{
				game->x_p = j;
				game->y_p = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	print_moves(t_game *game)
{
	char	*full_str;

	game->str_move = ft_itoa(game->move_counter);
	full_str = ft_strjoin("Move :", game->str_move);
	mlx_put_string(game->mlx, full_str, 15, 10);
	free(game->str_move);
	free(full_str);
}

void	win_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	close_game(game);
}
