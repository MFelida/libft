
NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC_DIR = src
SRC_FILES = ft_atof.c ft_atoi.c ft_atoi_base.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_putuint_fd.c ft_puthex_fd.c ft_printf.c ft_get_next_line.c \
	ft_realloc.c ft_exit.c ft_print_err.c\
	ft_get_next_line_utils.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
	ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

AR = ar
AFLAGS = -crs

GNL_BUFFER_SIZE = 1024

all: CFLAGS += -O3
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -DGNL_BUFFER_SIZE="$(GNL_BUFFER_SIZE)" -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

debug: CFLAGS += -gdwarf-2 -O0 -DDEBUG
debug: $(NAME)

re: fclean all

clean:
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ rm -f $(NAME)

.PHONY: clean fclean re all debug
