NAME			=	push_swap
BONUS_NAME		=	checker

CC				=	clang -g
AR				=	AR -rcs
RM				=	rm -rfd

LIBS_DIR		=	libs
INCLUDES_DIR	=	includes
P_S_DIR			=	src/push_swap

CHECKER_RAW		=	checker.c
CHECKER_FILES	=	$(addprefix $(P_S_DIR)/, $(CHECKER_RAW))

.PHONY: clean fclean re libft makechecker

all: $(NAME) $(BONUS_NAME)
	@echo $(CHECKER_FILES)

bonus: $(BONUS_NAME)

$(NAME): libft
	@echo "name"

$(BONUS_NAME): libft
	cp -u $(P_S_DIR)/push_swap.h $(INCLUDES_DIR)/push_swap.h
	$(CC) $(CHECKER_FILES) -L $(LIBS_DIR) -I $(INCLUDES_DIR) -lft -o $@

libft:
	make -C ./src/libft
	mkdir -p $(LIBS_DIR) includes
	cp ./src/libft/libft.h $(INCLUDES_DIR)/libft.h
	cp ./src/libft/libft.a $(LIBS_DIR)/libft.a

clean:
	make clean -C ./src/libft

fclean: clean
	make fclean -C ./src/libft
	$(RM) $(INCLUDES_DIR) $(LIBS_DIR)