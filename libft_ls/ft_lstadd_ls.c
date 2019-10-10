/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:00:29 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 22:30:01 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <string.h>
#include <sys/stat.h>
#include "ft_ls.h"

int		ft_lstadd_ls(t_ls **l, unsigned char flag, struct dirent *dirread)
{
	t_ls		*copy;
	t_ls		*prev;
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
			while (copy && copy->time_mod >= time_our)
			{
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
		if (ft_strcmp(dirread->d_name, prev->name) < 0)
		{
			if (!(*l = ft_lst_ls_new(dirread)))
				return (0);
			(*l)->next = prev;
		}
		else
		{
			while (copy && ft_strcmp(dirread->d_name, copy->name) >= 0)
			{
				prev = copy;
				copy = copy->next;
			}
			if (!(prev->next = ft_lst_ls_new(dirread)))
				return (0);
			prev->next->next = copy;
		}
	}
	return (1);
}
