/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:21:24 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 17:27:52 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>

#include "ft_ls.h"
#include <string.h>


int		ft_lstadd(t_list **l, unsigned char flags, struct dirent *dirread)
{
	t_list	*copy;


	flags+=0;
	copy = *l;
	while (copy->next)
		copy = copy->next;

	if (!(copy->next = ft_lst_ls_new(dirread)))
		return (0);
	return (1);
}
