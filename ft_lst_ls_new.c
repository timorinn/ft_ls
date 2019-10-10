/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ls_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:38:43 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 17:27:07 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include "ft_ls.h"
#include <stdlib.h>

t_list	*ft_lst_ls_new(struct dirent *dirread)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(list->name = ft_strdup(dirread->d_name)))
		return (NULL);
	list->type_file = dirread->d_type;
	list->next = NULL;
	return (list);
}
