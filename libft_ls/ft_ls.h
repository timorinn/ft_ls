/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:32:03 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 18:15:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <sys/types.h>
# include <sys/dir.h>

typedef struct		t_lst
{
	char			*name;
	int				type_file;
	struct t_lst	*next;
	long int		time_mod;
}					t_list;

int			ft_strdel(char **as);
t_list		*ft_lst_ls_new(struct dirent *dirread);
char		*ft_strdup(char const *src);
size_t		ft_strlen(const char *s);
int			ft_lstdel(t_list **l);
int			ft_lstadd(t_list **l, unsigned char flags, struct dirent *dirread);
t_list		*ft_make_list(DIR *dirp, unsigned char flag);

#endif