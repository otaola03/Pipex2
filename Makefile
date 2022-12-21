# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 19:18:14 by jperez            #+#    #+#              #
#    Updated: 2022/12/21 17:24:00 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M = mandatory/
B = bonus/
O = objs/
J = objs_b/
NAME = pipex

NAME_BONUS = pipex_bonus


#F = -fsanitize=address

CC = gcc -g3 $(F)

CFLAGS = -Wall -Werror -Wextra

RM = -rm -rf

SRCS = $Mmain.c $Mft_aux.c $Mft_get_cmd.c $Mft_get_files.c $Mft_split.c \
		$Mft_general_free.c $Mpipex.c $Mft_functions.c $Mft_manage_files.c \
		$Mft_check_argv.c

OBJS = $Omain.o $Oft_aux.o $Oft_get_cmd.o $Oft_get_files.o $Oft_split.o \
		$Oft_general_free.o $Opipex.o $Oft_functions.o $Oft_manage_files.o \
		$Oft_check_argv.o

SRCS_BONUS =  $Bmain_bonus.c $Bft_aux_bonus.c $Bft_get_cmd_bonus.c $Bft_get_files_bonus.c $Bft_split_bonus.c \
		$Bft_general_free_bonus.c $Bpipex_bonus.c $Bft_functions_bonus.c $Bft_manage_files_bonus.c \
		$Bft_here_doc_bonus.c $Bft_get_next_line_bonus.c\
		$Bft_check_argv.c

OBJS_BONUS = $Jmain_bonus.o $Jft_aux_bonus.o $Jft_get_cmd_bonus.o $Jft_get_files_bonus.o $Jft_split_bonus.o \
		$Jft_general_free_bonus.o $Jpipex_bonus.o $Jft_functions_bonus.o $Jft_manage_files_bonus.o \
		$Jft_here_doc_bonus.o $Jft_get_next_line_bonus.o\
		$Jft_check_argv.o

all: $(NAME)

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$J:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $O

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

$(OBJS_BONUS): | $J

$(OBJS): $O%.o: $M%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): $J%.o: $B%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $O $(OBJS_BONUS) $J

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: fclean clean all
