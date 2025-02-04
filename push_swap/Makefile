NAME = push_swap
SRC = push_swap.c handl_error.c creat_stack.c swap.c push.c rotate.c\
		reverse_rotate.c push_swap_utils.c small_stacks.c big_stacks.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf
HEADER = push_swap.h

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "Tout est make"

clean :
	@$(RM) $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@echo "TOUT EST CLEAN"

re : fclean all

.PHONY : clean all