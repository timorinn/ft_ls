# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 18:50:15 by bford             #+#    #+#              #
#    Updated: 2019/10/08 15:03:10 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =	-Wall -Werror -Wextra

exe:
		gcc $(FLAGS) *.c *.h
		./a.out

va:
	valgrind --leak-check=full ./a.out

git:
	git add -A && git commit -ma && git push