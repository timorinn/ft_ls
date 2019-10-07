/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:32:03 by bford             #+#    #+#             */
/*   Updated: 2019/10/07 20:18:46 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>

typedef struct		t_lst
{
	char			*name;
	struct t_lst	*next;
}					t_list;

int		ft_strdel(char **as);
t_list	*ft_lst_ls_new(char *s);
char	*ft_strdup(char const *src);
size_t	ft_strlen(const char *s);
int		ft_lstdel(t_list **l);
int		ft_lstadd(t_list **l, char *s);

#endif