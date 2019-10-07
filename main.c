#include <dirent.h> // OPENDIR / READDIR / CLOSEDIR
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "ft_ls.h"
int     main(void)
{
    DIR *dirp;
    struct dirent	*dirread;
    //struct stat		buff;
    t_list          *l;



    if (!(dirp = opendir(".")) && write(1, "NO DIR!!", 8))
        return (0);
    if (!(l = ft_lst_ls_new((readdir(dirp))->d_name)))
        return (ft_lstdel(&l));
    printf("LP 1 = %p\n", l);
    while ((dirread = readdir(dirp)))
    {
        if (!ft_lstadd(&l, dirread->d_name))
            return (ft_lstdel(&l));
        
		//printf("FILE = %15s | STAT = %3d | ", dirread->d_name, stat(dirread->d_name, &buff));
        /*
		printf("DATA = %ld.%02ld.%02ld.%02ld \n", 1970 + buff.st_mtime / 31536000,
		buff.st_mtime / 3600 % 24, buff.st_mtime / 60 % 60,
		buff.st_mtime % 60);
        */
        
    }
    while (l)
    {
        printf("FILE = = %s\n", l->name);
        l = l->next;
    }
    ft_lstdel(&l);
    closedir(dirp);
    return (1);
}
