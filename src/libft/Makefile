NAME		:=	libft.a

CC			:=	clang
AR			:=	ar -rc
RM			:=	rm -rfd
CFLAGS		:=	-Wall -Wextra -Werror

SRC_DIR		:=	src
OBJ_DIR		:=	objs

RAW			=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_litoa.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c

SRC		=	$(addprefix $(SRC_DIR)/,$(RAW))
OBJS	=	$(addprefix $(OBJ_DIR)/,$(RAW:.c=.o))

.PHONY: clean fclean re

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -I./ -o $@

all: $(NAME)

clean:	
	$(RM) $(OBJ_DIR)

fclean:
	$(RM) $(OBJ_DIR) $(NAME)

re:	fclean all
