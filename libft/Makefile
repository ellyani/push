NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER = libft.h

CC = cc

SRC = ft_atoi.c ft_itoa.c  ft_putendl_fd.c ft_strlcat.c ft_substr.c\
ft_bzero.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c\
ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c\
ft_isalnum.c ft_memcmp.c ft_split.c ft_strmapi.c\
ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strncmp.c\
ft_isascii.c ft_memmove.c ft_strdup.c ft_strnstr.c\
ft_isdigit.c ft_memset.c ft_striteri.c ft_strrchr.c\
ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c\
				ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
					ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstdelone_bonus.c

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

GREEN = \033[0;32m 
RED = \033[0;31m
PURPLE = \033[0;35m

all : $(NAME)

$(NAME) : $(OBJ) ${HEADER}
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)TOUT EST MAKE"

bonus : $(OBJ_BONUS) ${HEADER}
	@ar rc $(NAME) $(OBJ_BONUS)
	@echo "$(PURPLE)TOUT EST MAKE_AVEC_BONUSE"

%.o:%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)TOUT EST CLEAN"

re : fclean $(NAME)
