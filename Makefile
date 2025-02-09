# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:00:07 by aibn-che          #+#    #+#              #
#    Updated: 2024/01/03 17:53:59 by aibn-che         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = pipex

MSRCS = mandatory_pipex/pipex.c mandatory_pipex/m_utils1.c mandatory_pipex/m_utils2.c mandatory_pipex/m_utils3.c mandatory_pipex/m_utils4.c mandatory_pipex/m_utils5.c ft_printf/ft_printf.c ft_printf/print_characters.c ft_printf/print_hex.c ft_printf/print_numbers.c ft_printf/print_unsigned_int.c
BSRCS = bonus_pipex/pipex_bonus.c bonus_pipex/b_utils1.c bonus_pipex/b_utils2.c bonus_pipex/b_utils3.c bonus_pipex/b_utils4.c bonus_pipex/b_utils5.c bonus_pipex/get_next_line/get_next_line_utils.c bonus_pipex/get_next_line/get_next_line.c ft_printf/ft_printf.c ft_printf/print_characters.c ft_printf/print_hex.c ft_printf/print_numbers.c ft_printf/print_unsigned_int.c

MOBJS = $(MSRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o:%.c mandatory_pipex/pipex.h
	$(CC) -c $< -o $@

%.o:%.c bonus_pipex/pipex_bonus.h
	$(CC) -c $< -o $@

$(NAME): $(MOBJS)
	$(CC) -o $@ $^

bonus: $(BOBJS)
	$(CC) -o $(NAME) $^

clean :
	rm -f $(MOBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)

re : clean all
