/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:53:26 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 21:02:46 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_make_list(DIR *dirp, unsigned char flag)
{
	t_list			*list;
    struct dirent	*dirread;

	list = NULL;
	while ((dirread = readdir(dirp)))
	{
		if (!list)
		{
			if ((!(flag & 16) || (flag & 16 && (dirread->d_name)[0] != '.')) &&
			!(list = ft_lst_ls_new(dirread)))
			{
				ft_lstdel_ls(&list);
				return (NULL);
			}
        		//return (ft_lstdel(&list));
		}
		else if (!ft_lstadd_ls(&list, flag, dirread))
		{
			ft_lstdel_ls(&list);
			return (NULL);
		}
			//return (ft_lstdel(&list));
	}
	return (list);
}
