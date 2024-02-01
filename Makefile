SRC = 	./src/push_swap.c \
		./src/check_stack.c \
		./src/errors.c \
		./src/make_case_rotation.c \
		./src/rotation_case_ab.c \
		./src/rotation_case_ba.c \
		./src/rotation_combinations.c \
		./src/sorting_algo_three.c \
		./src/sorting_algo.c \
		./src/sorting_rotate_reverse.c \
		./src/sorting_ss_rr.c \
		./src/sorting_swap_push.c \
		./src/stack_list.c \
		./src/utils.c 

BONUS_SRC = ./check/checker.c \
			./check/checker_utils.c \
			./src/check_stack.c \
			./src/errors.c \
			./src/make_case_rotation.c \
			./src/rotation_case_ab.c \
			./src/rotation_case_ba.c \
			./src/rotation_combinations.c \
			./src/sorting_algo_three.c \
			./src/sorting_algo.c \
			./src/sorting_rotate_reverse.c \
			./src/sorting_ss_rr.c \
			./src/sorting_swap_push.c \
			./src/stack_list.c \
			./src/utils.c 

OBJS = ${SRC:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

RM = rm -f
NAME = push_swap
BONUS_NAME = checker
LFT = ./ft_printf/libftprintf.a ./libft/libft.a
LIB = -L ./ft_printf -lftprintf -L ./libft -lft

all :  ${NAME}

${LFT}:
				@make -s -C ./ft_printf/ all
				@make -s -C ./libft/ all

${NAME} :    ${OBJS} ${LFT} 
				@gcc -Wall -Werror -Wextra -g ${OBJS} ${LIB} -o ${NAME}
				@echo "\033[32m✅ Done !\033[0m"

${BONUS_NAME} : ${BONUS_OBJ} ${LFT} 				
				@gcc -Wall -Werror -Wextra -g ${BONUS_OBJ} ${LIB} -o ${BONUS_NAME}
				@echo "\033[32m✅ Checker Done !\033[0m"

bonus : ${BONUS_NAME} # Alias 'bonus' to 'checker'

clean :
				@${RM} ${OBJS} ${BONUS_OBJ}
				@make -s -C ./ft_printf/ clean
				@make -s -C ./libft/ clean
fclean :    clean
						@${RM} ${NAME} ${BONUS_NAME}
						@make -C ./ft_printf/ fclean
						@make -C ./libft/ fclean

re: fclean all
.PHONY: all clean fclean re bonus checker


#save: fclean
#	git add .
#	git commit -m "make save"
#	git push
