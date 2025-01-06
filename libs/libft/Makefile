# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 20:31:36 by umeneses          #+#    #+#              #
#    Updated: 2024/05/14 13:59:45 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
RESET			:= \033[0m

# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

SRC_D				= ./src/
HEADERS_D			= ./includes/
BUILD_D				= ./build/

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

NAME 				= libft.a

FILES				= ft_atoi.c
FILES				+= ft_bzero.c
FILES				+= ft_calloc.c
FILES				+= ft_isalnum.c
FILES				+= ft_isalpha.c
FILES				+= ft_isascii.c
FILES				+= ft_isdigit.c
FILES				+= ft_isprint.c
FILES				+= ft_memchr.c
FILES				+= ft_memcmp.c
FILES				+= ft_memcpy.c
FILES				+= ft_memmove.c
FILES				+= ft_memset.c
FILES				+= ft_strchr.c
FILES				+= ft_strdup.c
FILES				+= ft_strlcat.c
FILES				+= ft_strlcpy.c
FILES				+= ft_strlen.c
FILES				+= ft_strncmp.c
FILES				+= ft_strnstr.c
FILES				+= ft_strrchr.c
FILES				+= ft_tolower.c
FILES				+= ft_toupper.c
FILES				+= ft_substr.c
FILES				+= ft_itoa.c		
FILES				+= ft_putchar_fd.c
FILES				+= ft_putstr_fd.c
FILES				+= ft_putendl_fd.c
FILES				+= ft_putnbr_fd.c
FILES				+= ft_striteri.c
FILES				+= ft_strmapi.c
FILES				+= ft_strjoin.c
FILES				+= ft_split.c	
FILES				+= ft_strtrim.c
# ****** libft functions ****** #
FILES				+= ft_lstadd_back_void.c
FILES				+= ft_lstadd_front_void.c
FILES				+= ft_lstclear_void.c
FILES				+= ft_lstdelone_void.c
FILES				+= ft_lstiter_void.c
FILES				+= ft_lstlast_t_list.c
FILES				+= ft_lstmap_t_list.c
FILES				+= ft_lstnew_t_list.c
FILES				+= ft_lstsize_int.c
FILES				+= ft_lstend_void.c
# ****** bonus libft functions ****** #
FILES				+= ft_printf.c
FILES				+= ft_printf_placeholder.c
FILES				+= ft_put_unsigned_nbr.c
FILES				+= ft_putnbrbase.c
FILES				+= ft_putptr.c
# ****** ft_printf functions ****** #
FILES				+= ft_get_next_line.c
FILES				+= ft_gnl_clear_nodes.c
FILES				+= ft_gnl_get_let.c
FILES				+= ft_gnl_get_line.c
FILES				+= ft_gnl_join_let.c
FILES				+= ft_gnl_join_line.c
# ****** gnl functions ****** #
FILES				+= ft_error_msg.c
FILES				+= ft_dec_to_binary.c
FILES				+= ft_strreversing_order.c
# ****** my functions ****** #

SRC_FILES			= $(addprefix $(SRC_D), $(FILES))

OBJS 				= $(addprefix $(BUILD_D), $(SRC_FILES:%.c=%.o))

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

AR 					= ar -rcs
RM 					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR				= umeneses
CC 					= cc
CFLAGS 				= -Wall -Wextra -Werror $(DFLAGS)
CPPFLAGS			= $(addprefix -I , $(HEADERS_D)) -MMD -MP
DFLAGS				= -g3
COMPILE_OBJS		= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_LIB			= @$(AR) $(NAME) $(OBJS)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all:				$(NAME)

$(BUILD_D)%.o:		%.c
					@printf "$(YELLOW)"
					@$(MKDIR) $(dir $@)
					@$(COMPILE_OBJS)
					
					@echo "Compiling LIBFT: $(notdir $<)"

$(NAME):			$(OBJS)
					@$(COMPILE_LIB)
					@printf "$(GREEN)"
					@echo "LIBFT Ready!"
					@printf "$(RESET)"

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects..."
					@printf "$(PURPLE)"
					$(RM) $(OBJS)
					$(RM) $(BUILD_D)
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables..."
					@printf "$(PURPLE)"
					$(RM) $(NAME)
					@printf "$(RESET)"

re:					fclean all

.PHONY:				all clean fclean re $(NAME)


