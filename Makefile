SRC		=		mandatory/create_stack.c \
				mandatory/fill_array.c \
				mandatory/find_bound.c \
				mandatory/ft_atol_checker.c \
				mandatory/is_sorted.c \
				mandatory/lst_control.c \
				mandatory/main.c \
				mandatory/push_move.c \
				mandatory/reverse_rotate_move.c \
				mandatory/rotate_move.c \
				mandatory/shortcut_way.c \
				mandatory/sign_cost.c \
				mandatory/sort_three.c \
				mandatory/start_sort.c \
				mandatory/swap_move.c \
				mandatory/the_big_sort.c \
				mandatory/update_position.c

B_SRC	=		bonus/create_stack_bonus.c \
				bonus/fill_array_bonus.c \
				bonus/ft_atol_checker_bonus.c \
				bonus/is_sorted_bonus.c \
				bonus/lst_control_bonus.c \
				bonus/main_bonus.c \
				bonus/push_move_bonus.c \
				bonus/reverse_rotate_move_bonus.c \
				bonus/rotate_move_bonus.c \
				bonus/swap_move_bonus.c \
				bonus/update_position_bonus.c

OBJ			=	$(SRC:.c=.o)
B_OBJ		=	$(B_SRC:.c=.o)
NAME		=	push_swap
CHECKER		=	checker
CFLAGS		=	-Wall -Wextra -Werror
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(CFLAGS) $(OBJ) -I$(LIBFT_DIR) -o $(NAME) -L$(LIBFT_DIR) -lft

$(OBJ): $(LIBFT)
	cc $(CFLAGS) -c -I$(LIBFT_DIR) $(@:.o=.c) -o $(@)

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
	cc $(CFLAGS) $(B_OBJ) -I$(LIBFT_DIR) -o $(CHECKER) -L$(LIBFT_DIR) -lft

$(B_OBJ): $(LIBFT)
	cc $(CFLAGS) -c -I$(LIBFT_DIR) $(@:.o=.c) -o $(@)

.PHONY: all clean fclean re bonus
