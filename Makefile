SRC		=	create_stack.c \
				fill_array.c \
				find_bound.c \
				ft_atol_checker.c \
				is_sorted.c \
				lst_control.c \
				main.c \
				push_move.c \
				reverse_rotate_move.c \
				rotate_move.c \
				shortcut_way.c \
				sign_cost.c \
				sort_three.c \
				start_sort.c \
				swap_move.c \
				the_big_sort.c \
				update_position.c

B_SRC	=		create_stack_bonus.c \
				fill_array_bonus.c \
				ft_atol_checker_bonus.c \
				is_sorted_bonus.c \
				lst_control_bonus.c \
				main_bonus.c \
				push_move_bonus.c \
				reverse_rotate_move_bonus.c \
				rotate_move_bonus.c \
				swap_move_bonus.c \
				update_position_bonus.c

OBJ			=	$(SRC:.c=.o)
B_OBJ		=	$(B_SRC:.c=.o)
NAME		=	push_swap
CHECKER		=	checker
CFLAGS		=	-Wall -Wextra -Werror
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

$(OBJ): $(LIBFT)
	cc $(CFLAGS) -c $(@:.o=.c) -o $(@)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	rm -f $(OBJ)
	rm -f $(B_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(CHECKER)

$(CHECKER): $(B_OBJ) $(LIBFT)
	cc $(CFLAGS) $(B_OBJ) -o $(CHECKER) -L$(LIBFT_DIR) -lft

$(B_OBJ): $(LIBFT)
	cc $(CFLAGS) -c $(@:.o=.c) -o $(@)

.PHONY: all clean fclean re bonus
