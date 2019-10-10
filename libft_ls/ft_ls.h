/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:32:03 by bford             #+#    #+#             */
/*   Updated: 2019/10/10 22:23:57 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <sys/types.h>
# include <sys/dir.h>

typedef struct		t_ls
{
	char			*name;
	int				type_file;
	struct t_ls	*next;
	long int		time_mod;
}					t_ls;

int			ft_strdel_ls(char **as);
t_ls		*ft_lst_ls_new(struct dirent *dirread);
char		*ft_strdup(char const *src);
size_t		ft_strlen(const char *s);
int			ft_lstdel_ls(t_ls **l);
int			ft_lstadd_ls(t_ls **l, unsigned char flags, struct dirent *dirread);
t_ls		*ft_make_list(DIR *dirp, unsigned char flag);
int			ft_strcmp(const char *s1, const char *s2);

#endif