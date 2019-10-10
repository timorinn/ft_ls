# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 11:34:46 by bford             #+#    #+#              #
#    Updated: 2019/10/10 18:14:57 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

LIBFT_LS =		./libft_ls

FLAGS =		-Wall -Werror -Wextra

clean:		
			/bin/rm -f *.o
			/bin/rm -f ft_ls.h.gch

fclean: 	clean
			
			
re:			fclean all

norm:		
			norminette $(LIBFT) $(FT_PRINTF)

exe:
			gcc $(FLAGS) -c $(LIBFT_LS)/*.c
			gcc $(FLAGS) -c -I $(LIBFT_LS) main.c
			gcc $(FLAGS) *.o
			make fclean
			./a.out

push:
			git add -A && git commit -ma && git push

va:
			valgrind --leak-check=full ./a.out