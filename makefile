# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/25 17:17:38 by matheme      #+#   ##    ##    #+#        #
#    Updated: 2019/02/28 23:59:01 by matheme     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# nom des executable
NAME1 = checker
NAME2 = push_swap

# les routes
SRC_PATH	= src
OBJ_PATH	= obj
INC_PATH	= includes
LIB_PATH	= librairies

# nom des fichier code source (*.c)
NAME_SRC_CHECKER	= c_checker.c\
					  c_order.c\
					  cp_order_effect.c\
					  cp_order_effect2.c\
					  cp_params.c
NAME_SRC_PUSH_SWAP	= p_home_sorting_algo2_0.c\
					  p_home_sorting_algo2_1.c\
					  p_home_sorting_algo2_2.c\
					  p_mediane.c\
					  p_order.c\
					  p_order2.c\
					  p_push_swap.c\
					  p_sorting_fusion_algo0_0.c\
					  p_sorting_fusion_alog0_1.c\
					  p_sorting_fusion_upgrade_algo1_1.c\
					  p_sorting_fusion_upgrade_algo1_2.c\
					  p_sorting_fusion_upgrade_algo1_3.c\
					  cp_order_effect.c\
					  cp_order_effect2.c\
					  cp_params.c

#nom des ficher objects (*.o)
NAME_OBJ_CHECKER = $(NAME_SRC_CHECKER:.c=.o)
NAME_OBJ_PUSH_SWAP = $(NAME_SRC_PUSH_SWAP:.c=.o)

#les sources
SRC_CHECKER		= $(addprefix $(SRC_PATH)/,$(NAME_SRC_CHECKER))
SRC_PUSH_SWAP	= $(addprefix $(SRC_PATH)/,$(NAME_SRC_PUSH_SWAP))

# les objects
OBJ_CHECKER		= $(addprefix $(OBJ_PATH)/,$(NAME_OBJ_CHECKER))
OBJ_PUSH_SWAP	= $(addprefix $(OBJ_PATH)/,$(NAME_OBJ_PUSH_SWAP))

#compilateur + flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#librairies
LIBFT	= $(LIB_PATH)/libft
LIBFT.A = $(LIBFT)/libft.a

all : $(NAME1) $(NAME2)
	@echo "\033[0;32m [--- COMPILATION TERMINEE ---] \033[0m"

$(NAME1) : $(OBJ_CHECKER) $(LIBFT.A)
	@$(CC) -I $(LIBFT) -L $(LIBFT) $^ -o $@
	@echo "\033[0;32m [--- CHECKER COMPILER ---] \033[0m"


$(NAME2) : $(OBJ_PUSH_SWAP) $(LIBFT.A)
	@$(CC) -I $(LIBFT) -L $(LIBFT) $^ -o $@
	@echo "\033[0;32m [--- PUSH_SWAP COMPILER ---] \033[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(LIBFT) -I $(INC_PATH) -c $< -o $@

$(LIBFT.A) :
	@make -C $(LIBFT)

clean :
	@rm -fv $(OBJ_CHECKER)
	@rm -fv $(OBJ_PUSH_SWAP)
	@make -C $(LIBFT) clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -fv $(NAME1)
	@rm -fv $(NAME2)
	@echo "\033[0;31m [--- EXECUTABLES SUPPRIMER ---] \033[0m"

re: fclean all
