# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:13:39 by umeneses          #+#    #+#              #
#    Updated: 2025/01/06 13:13:39 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
RESET			:= \033[0m

# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

SRC_D					= ./src/
BONUS_D					= ./bonus/
BUILD_D					= ./build/
LIBS_D					= ./libs/
LIBFT_D					= $(LIBS_D)libft/
MLX42_D					= $(LIBS_D)codam/
MLX42_BUILD				= $(MLX42_D)build/
HEADERS_ADDED			= $(LIBFT_D)includes/
HEADERS_ADDED			+= $(MLX42_D)include/MLX42/
HEADERS_ADDED			+= $(BONUS_D)headers/
HEADERS					= ./headers/ $(HEADERS_ADDED)

TDD_UTILS_D				= ./_tdd_utils/
# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBFT					= $(addprefix $(LIBFT_D), libft.a)
MLX42					= $(addprefix $(MLX42_BUILD), libmlx42.a)
LIBS					= $(LIBFT) $(MLX42)

NAME					= cub3d

SRC_FILES				= 01.main.c
SRC_FILES				+= 02.struct_mem_alloc.c
SRC_FILES				+= clear_all.c
SRC_FILES				+= map_validation/map_validation.c
SRC_FILES				+= map_validation/invalid_extension.c
SRC_FILES				+= map_validation/map_opener.c
SRC_FILES				+= map_validation/map_reader.c
SRC_FILES				+= map_validation/map_printer.c
SRC_FILES				+= map_validation/map_compass_datafinder.c
SRC_FILES				+= map_validation/unique_def_compass.c
SRC_FILES				+= map_validation/no_garbage_manager.c
SRC_FILES				+= map_validation/nothing_aftermap.c
SRC_FILES				+= map_validation/map_array_printer.c
SRC_FILES				+= map_validation/map_struct_init.c
SRC_FILES				+= map_validation/map_struct_skippers.c
SRC_FILES				+= map_validation/map_colors_manager.c
SRC_FILES				+= map_validation/map_colors.c
SRC_FILES				+= map_validation/texture_path_validation.c
SRC_FILES				+= map_validation/closed_wall_bottomwall.c
SRC_FILES				+= map_validation/closed_wall_middlewall.c
SRC_FILES				+= map_validation/closed_wall_topwall.c
SRC_FILES				+= map_validation/player_checker.c


SRC_FILES_ALL			= $(addprefix $(SRC_D), $(SRC_FILES))

#TDD_FILES				= ft_lst_printer.c
#TDD_FILES				+= ft_env_printer.c
#TDD_FILES				+= ft_array_printer.c
#TDD_FILES_ALL			= $(addprefix $(TDD_UTILS_D), $(TDD_FILES))
#TDD_OBJS_FILES			= $(addprefix $(BUILD_D), $(TDD_FILES_ALL:%.c=%.o))

OBJS_FILES				= $(addprefix $(BUILD_D), $(SRC_FILES_ALL:%.c=%.o))
OBJS_ALL				= $(TDD_OBJS_FILES) $(OBJS_FILES)

# **************************** #
#			BONUS			   #
# **************************** #

NAME_BONUS				= cub3d_bonus

SRC_FILES_BONUS			= $(SRC_FILES_ALL)

SRC_BONUS_ALL			= $(addprefix $(SRC_BONUS_D), $(SRC_FILES_BONUS))

OBJS_FILES_BONUS		= $(addprefix $(BUILD_D), $(SRC_BONUS_ALL:%.c=%.o))
OBJS_ALL_BONUS			= $(OBJS_FILES_BONUS)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								DEFINES										   #
# **************************************************************************** #

define	project_title
		@printf "$(CYAN)"
		@echo "                                                                    "
		@echo "#########################    WELCOME TO    #########################"
		@echo "                         _            ___________                   "
		@echo "                        | |          |____ |  _  \                  "
		@echo "               ___ _   _| |__   ___      / / | | |                  "
		@echo "              / __| | | | '_ \ / _ \     \ \ | | |                  "
		@echo "             | (__| |_| | |_) |  __/ .___/ / |/ /                   "
		@echo "              \___|\__,_|_.__/ \___| \____/|___/          ♥‿♥       "
		@echo "                                                                    "
		@echo "####################################################################"
		@printf "$(RESET)"
endef

define	project_title_bonus
		@printf "$(CYAN)"
		@echo "                                                                    "
		@echo "#########################    WELCOME TO    #########################"
		@echo "                         _            ___________                   "
		@echo "                        | |          |____ |  _  \                  "
		@echo "               ___ _   _| |__   ___      / / | | |                  "
		@echo "              / __| | | | '_ \ / _ \     \ \ | | |                  "
		@echo "             | (__| |_| | |_) |  __/ .___/ / |/ /                   "
		@echo "              \___|\__,_|_.__/ \___| \____/|___/          ♥‿♥       "
		@echo "                                                                    "
		@echo "#########################       BONUS      #########################"
		@printf "$(RESET)"
endef

define					instructions
						@echo "Welcome to our version of Cube3D!"
						@echo "Hit ./$(NAME) and call any map to start"

endef

define					instructions_bonus
						@echo "Are you ready to run Cube3D with adrenaline???"
						@echo "Hit ./$(NAME_BONUS) and call any command to start"
endef

ifdef					WITH_BONUS
	NAME				= $(NAME_BONUS)
	OBJS_FILES			= $(OBJS_FILES_BONUS)
	OBJS_ALL			= $(OBJS_ALL_BONUS)
	project_title		= $(project_title_bonus)
	instructions		= $(instructions_bonus)
endif

define					bonus
						$(MAKE) WITH_BONUS=TRUE --no-print-directory
endef

define					map_for_test
						maps/default.cub
endef

define					function_for_debug
						color_digits_counter
endef

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR		= gigardin && umeneses
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= $(addprefix -I, $(HEADERS)) -MMD -MP
LDLIBS		= $(addprefix -L, $(dir $(LIBS)))
LDFLAGS		= -lft -ldl -lglfw -pthread -lm
COMP_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE	= $(CC) $(CFLAGS) $(OBJS_ALL) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all: 				libft_lib mlx_lib $(NAME)

$(BUILD_D)%.o:		%.c
					@$(MKDIR) $(dir $@)
					@$(COMP_OBJS)
					@printf "$(CYAN)"
					@echo "$(NAME)	compiling -> $(GREEN)$(notdir $<)"
					@printf "$(RESET)"

$(NAME):			$(OBJS_ALL)
					@$(COMP_EXE)
					@printf "$(GREEN)"
					@echo "--------------------------------------------------------------------"
					@echo "		$(NAME) READY!"
					@echo "--------------------------------------------------------------------"
					$(call project_title)
					@printf "$(YELLOW)"
					$(call instructions)
					@printf "$(RESET)"

libft_lib:
					@printf "$(YELLOW)"
					@echo ">>> Checking LIBFT"
					@printf "$(CYAN)"
					@$(MAKE) -C $(LIBFT_D) --no-print-directory
					@printf "$(YELLOW)"
					@printf "$(RESET)"

mlx_lib:
#					@cmake $(MLX42_D) -B $(MLX42_D)build
#					@$(MAKE) -C $(MLX42_D)build -j4 --no-print-directory

bonus:
					$(call bonus)

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects from: $(PURPLE) $(NAME)"
					@$(RM) $(OBJS)
					@$(RM) $(BUILD_D)
					@$(MAKE) -C $(LIBFT_D) fclean --no-print-directory
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables from: $(PURPLE) $(NAME)"
					@$(RM) $(NAME)
					@$(RM) $(NAME_BONUS)
					@printf "$(RESET)"

re:					fclean all

run:				all
					./$(NAME)

go:					all
					./$(NAME) $(call map_for_test)

gdb:				all
					gdb --tui \
					-ex 'b main' \
					-ex 'b $(call function_for_debug)' \
					-ex 'set args $(call map_for_test)' \
					-ex 'set detach-on-fork off' \
					-ex 'info inferiors' ./$(NAME)

val:				re
					valgrind --leak-check=full \
					--track-origins=yes \
					--trace-children-skip='*/bin/*,*/sbin/*,/usr/bin/*' \
					--trace-children=yes \
					--track-fds=yes \
					--show-reachable=yes\
					--suppressions=mlx_suppressions.sup \
					./$(NAME)  $(call map_for_test)

.PHONY:				all clean fclean re bonus min val gdb