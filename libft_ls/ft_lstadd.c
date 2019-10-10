/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:21:24 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 20:51:23 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <string.h>
#include <sys/stat.h>
#include "ft_ls.h"

int		ft_lstadd(t_list **l, unsigned char flag, struct dirent *dirread)
{
	t_list		*copy;
	t_list		*prev;
	long int	time_our;
	struct stat	buff;

	stat(dirread->d_name, &buff);
	prev = *l;
	copy = *l;
	time_our = buff.st_mtime;
	if (flag & 4)
	{
		if (time_our > prev->time_mod)
		{
			if (!(*l = ft_lst_ls_new(dirread)))
				return (0);
			(*l)->next = prev;
		}
		else
		{
			while (copy->next && copy->time_mod >= time_our)
			{
				printf("%p\n", copy->next);
				prev = copy;
				copy = copy->next;
			}
			if (!(prev->next = ft_lst_ls_new(dirread)))
				return (0);
			prev->next->next = copy;
		}
	}
	else
	{
		while (copy->next)
			copy = copy->next;
		if (!(copy->next = ft_lst_ls_new(dirread)))
			return (0);
	}
	//if (!(copy->next = ft_lst_ls_new(dirread)))
	//	return (0);
	return (1);
}
