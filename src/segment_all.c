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

static void seg_x(t_point *pt, t_env env)
{
	int		i;
	int     k;
    int     j;

	k = 1;
    j = 0;
	while (k++ < env.nbry)
	{
		i = env.nbrx;
		while (--i)
		{
			segment(pt[j], pt[j + 1], env);
			++j;
		}
        ++j;
	}
}

void	trace(t_env env)
{
    int     k;
    int     len;

    seg_x(env.pt, env);
	k = -1;
    len = env.nbrx * (env.nbry - 1);
    while (++k < len)
		if (k % env.nbrx)
            segment(env.pt[k], env.pt[k + env.nbrx], env);
}
