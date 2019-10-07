/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:21:24 by bford             #+#    #+#             */
/*   Updated: 2019/10/07 20:25:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_ls.h"
#include <string.h>


int		ft_lstadd(t_list **l, char *s)
{
	t_list	*copy;

	copy = *l;
	while (copy->next)
		copy = copy->next;
	if (!(copy->next = ft_lst_ls_new(s)))
		return (0);
	return (1);
}
