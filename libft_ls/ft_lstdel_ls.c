/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:00:22 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 21:10:32 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

int		ft_lstdel_ls(t_list **l)
{
	if (l && *l)
	{
		if ((*l)->next)
			ft_lstdel_ls(&((*l)->next));
		ft_strdel_ls(&((*l)->name));
		free(*l);
		*l = NULL;
	}
	return (0);
}
