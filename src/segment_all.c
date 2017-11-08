/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:24:40 by amansour          #+#    #+#             */
/*   Updated: 2017/11/06 13:43:23 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void seg_x(t_point *pt, t_env *env)
{
	int		i;
	int     k;
    int     j;

	k = 1;
    j = 0;
	while (k++ < env->nbry)
	{
		i = env->nbrx;
		while (--i)
		{
			segment(pt[j], pt[j + 1], env);
			++j;
		}
        ++j;
	}
}

void	trace(t_env *env)
{
    int     k;
 	int     len;
   	t_point *p;

   	if (env->p)
    	p = env->p;
    else if (env->zpt)
    	p = env->zpt;
    else
    	p = env->pt;
    printf("JE SUIS DEDANS\n");
    display_point(p, 10);
    seg_x(p, env);
     printf("JE SUIS DEDANS\n");
	k = -1;
    len = env->nbrx * (env->nbry - 1);
    while (++k < len)
		if (k % env->nbrx)
            segment(p[k], p[k + env->nbrx], env);
    mlx_put_image_to_window(env->mlx, env->win, env->imag, 0, 0);
}

int	draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	init_imag(e);
	trace(e);
	return (0);
}