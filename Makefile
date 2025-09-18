# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 16:02:07 by sidrissi          #+#    #+#              #
#    Updated: 2025/09/18 21:27:16 by sidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror #-fsanitize=address -g3
RM      = rm -f
FILES	=	mandatory/get_next_line.c mandatory/ft_parsing.c mandatory/ft_parsing_map.c mandatory/ft_parsing_map2.c \
			mandatory/init_window.c mandatory/init_window_2.c mandatory/init_window_1.c mandatory/ft_parsing_1.c \
			mandatory/ft_parsing_2.c mandatory/ft_parsing_22.c mandatory/ft_parsing_helper_3.c mandatory/ft_parsing_4.c\
			mandatory/ft_parsing_5.c\
			libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcpy.c \
			libft/ft_strlen.c libft/ft_substr.c libft/ft_strchr.c libft/ft_split.c libft/free_2d_array.c \
			libft/ft_memset.c libft/ft_atoi.c libft/ft_count_2d_array.c libft/ft_strcmp.c libft/ft_isdigit.c \
			libft/ft_strtrim.c libft/ft_lstnew.c libft/ft_lstaddback.c libft/ft_lstlast.c libft/ft_strstr.c libft/ft_strtrim_end.c \
			recasting/recasting.c recasting/helper_recasting.c projection/projection.c recasting/helper_recasting_1.c\
			projection/decster_put_img.c projection/dcster_prt_tow.c 




OBJECT  = $(FILES:.c=.o)
NAME    = cub3D


MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) $(MLX_FLAGS) -o $(NAME)
	

%.o: %.c include/cub3d.h
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@



# libft/%.o: libft/%.c bonus/cub3d_bonus.h 
# 	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# projection/%.o: projection/%.c include/cub3d.h
# 	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# recasting/%.o: recasting/%.c include/cub3d.h
# 	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	$(RM) $(OBJECT) 

fclean: clean
	$(RM) $(NAME)

re: fclean all
