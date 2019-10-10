/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ls_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:38:43 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 18:13:02 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include "ft_ls.h"
#include <stdlib.h>
#include <sys/stat.h>

t_list	*ft_lst_ls_new(struct dirent *dirread)
{
	t_list			*list;
	struct stat     buff;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(list->name = ft_strdup(dirread->d_name)))
		return (NULL);
	list->type_file = dirread->d_type;
	stat(list->name, &buff);
	list->time_mod = buff.st_mtime;
	list->next = NULL;
	return (list);
}
