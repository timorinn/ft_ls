#include <dirent.h> // OPENDIR / READDIR / CLOSEDIR
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h> // getpwuid
#include <grp.h>
#include <sys/xattr.h> // listxattr
#include <time.h>

#include "ft_ls.h"

int		ft_strchr_ind(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (*s == c)
		return (i);
	return(-1);
}

unsigned char	pars_flags(int argc, char **argv, unsigned char *flags)
{
	int	i;
	int	i2;

	i = 1;
	i2 = 1;
	*flags = 0;
	while (i < argc)
	{
		printf("WAT 1 ?\n");
		if (argv[i][0] == '-')
		{
			i2 = 1;
			printf("WAT 2 ?\n");
			while (argv[i][i2] == 'a' || argv[i][i2] == 'r' || argv[i][i2] == 't' ||
			argv[i][i2] == 'l' || argv[i][i2] == 'R')
			{
				if (argv[i][i2] == 'a')
					*flags |= 16;
				else if (argv[i][i2] == 'r')
					*flags |= 8;
				else if (argv[i][i2] == 't')
					*flags |= 4;
				else if (argv[i][i2] == 'l')
					*flags |= 2;
				else
					*flags |= 1;
				i2++;
			}
		}
		i++;
	}
	return (*flags);
}

int     main(int argc, char **argv)
{
	unsigned char	flags;

    DIR *dirp;
    struct dirent	*dirread;
	/*
    struct stat     buff;
    struct passwd   *user_name;
    struct group    *group_name;
    struct tm       *mytime;
	*/
    t_list          *l;
	t_list			*copy_list;

    /*
    size_t          buffsize;
    buffsize = 10000;
    char            bufff[buffsize + 1];
	*/
	flags = pars_flags(argc, argv, &flags);
	printf("FLAGS = %hhu\n", flags);
    if (!(dirp = opendir(".")) && write(1, "NO DIR!!", 8))
        return (0);
	
    if (!(l = ft_lst_ls_new((readdir(dirp))->d_name)))
        return (ft_lstdel(&l));
	copy_list = l;
    while ((dirread = readdir(dirp)))
    {
        if (!ft_lstadd(&l, dirread->d_name))
            return (ft_lstdel(&copy_list));
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
		
		/*
        printf("stat =%d ", stat(l->name, &buff));
        user_name = getpwuid(buff.st_uid);
        group_name = getgrgid(buff.st_gid);
		mytime = localtime(&(buff.st_mtime));
        printf("%6lo %2hu %s  %s %7lld %s\n", (unsigned long)(buff.st_mode), buff.st_nlink, user_name->pw_name, group_name->gr_name, buff.st_size, l->name);
		printf("lstat=%d ", lstat(l->name, &buff));
		*/
		//printf("%6lo %2hu %s  %s %7lld %2d %d %02d:%02d %s\n", (unsigned long)(buff.st_mode), buff.st_nlink, user_name->pw_name, group_name->gr_name, buff.st_size, mytime->tm_mday, mytime->tm_mon, mytime->tm_hour, mytime->tm_min, l->name);
        //bufff[readlink(l->name, bufff, buffsize)] = '\0';
        //printf("READLINK_BUFF = %s\n\n", bufff); // НА ЧТО ССЫЛАЕТСЯ ССЫЛКА
		//printf("time = %s", ctime(&(buff.st_mtime)));


        //printf("USER ACCESS = %llu %lo\n", buff.st_ino, (unsigned long)buff.st_mode);
        l = l->next;
    }
    ft_lstdel(&copy_list);
    closedir(dirp);
    return (1);
}
