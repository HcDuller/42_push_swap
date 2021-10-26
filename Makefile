NAME			=	push_swap
BONUS_NAME		=	checker

CC				=	clang
AR				=	AR -rcs
RM				=	rm -rfd

LIB_DIR			=	libs
INCLUDES_DIR	=	includes


.PHONY: clean fclean re libft

all: $(NAME) $(BONUS_NAME)
	echo "all"

$(NAME):
	echo "name"

$(BONUS_NAME):
	echo "bonus_name"

libft:
	make -C ./src/libft
	mkdir -p $(LIB_DIR) includes
	cp ./src/libft/libft.a ./includes/libft.h
	cp ./src/libft/libft.a ./libs/libft.a

clean:
	make clean -C ./src/libft

fclean: clean
	make fclean -C ./src/libft