# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 09:02:42 by hmochida          #+#    #+#              #
#    Updated: 2021/10/18 09:05:34 by hmochida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

valgrind --tool=memcheck --track-origins=yes --leak-check=yes ./fdf x.fdf