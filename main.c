#include <dirent.h> // OPENDIR / READDIR / CLOSEDIR
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h> // getpwuid
#include <grp.h>
#include <sys/xattr.h> // listxattr

#include "ft_ls.h"
int     main(void)
{
    DIR *dirp;
    struct dirent	*dirread;
    struct stat     buff;
    struct passwd   *user_name;
    struct group    *group_name;
    t_list          *l;


    if (!(dirp = opendir(".")) && write(1, "NO DIR!!", 8))
        return (0);
    if (!(l = ft_lst_ls_new((readdir(dirp))->d_name)))
        return (ft_lstdel(&l));
    while ((dirread = readdir(dirp)))
    {
        if (!ft_lstadd(&l, dirread->d_name))
            return (ft_lstdel(&l));

        //stat(dirread->d_name, &buff);
        //printf("USER_NAME = %s\n", user_name->pw_name); // ВЫВОД ИМЕНИ ПОЛЬЗОВАТЕЛЯ
        //printf("GROUP_NAME = %s\n", group_name->gr_name); // ВЫВОД ИМЕНИ ПОЛЬЗОВАТЕЛЯ
		//printf("FILE = %15s | STAT = %3d | ", dirread->d_name, stat(dirread->d_name, &buff)); // ВЫВОД НАЗВАНИЯ ФАЙЛА И РЕЗУЛЬТАТОВ STAT
        //printf("%lld\n", buff.st_size);
        /*
		printf("DATA = %ld.%02ld.%02ld.%02ld \n", 1970 + buff.st_mtime / 31536000, 
		buff.st_mtime / 3600 % 24, buff.st_mtime / 60 % 60,
		buff.st_mtime % 60);
        // НЕЗАКОНЧЕННОЕ ВЫЧИСЛЕНИЕ ДАТЫ ИЗМЕНЕНИЯ ФАЙЛА
        */
        
    }
    while (l)
    {
        printf("stat =%d ", stat(l->name, &buff));
        user_name = getpwuid(buff.st_uid);
        group_name = getgrgid(buff.st_gid);
	
        printf("%6lo %2hu %s  %s %7lld %s\n", (unsigned long)(buff.st_mode), buff.st_nlink, user_name->pw_name, group_name->gr_name, buff.st_size, l->name);
		printf("lstat=%d ", lstat(l->name, &buff));
		printf("%6lo %2hu %s  %s %7lld %s\n\n", (unsigned long)(buff.st_mode), buff.st_nlink, user_name->pw_name, group_name->gr_name, buff.st_size, l->name);

        //printf("USER ACCESS = %llu %lo\n", buff.st_ino, (unsigned long)buff.st_mode);
        l = l->next;
    }
    ft_lstdel(&l);
    closedir(dirp);
    return (1);
}
