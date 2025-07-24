# **************************************************************************** #
#                                  Project Name                                #
# **************************************************************************** #

NAME = libft.a

# **************************************************************************** #
#                             Compiler & Commands                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -rf
MAKE		= make --no-print-directory

# **************************************************************************** #
#                                 Output Formatting                            #
# **************************************************************************** #

ESC			= \033[
RST			= 0m

# Styles
B			= 1;#	Bold
D			= 2;#	Dim
I			= 3;#	Italic
U			= 4;#	Underline
BL			= 5;#	Blink
ST			= 9;#	Strikethrough

# Colors
C_MAGENTA	= 95m#	Cleaned files but program still works
C_RED		= 91m#	Program doesn't work anymore
C_GREEN		= 92m#	Program is working
C_YELLOW	= 93m#	Message
C_LOGO		= 96m

# **************************************************************************** #
#                                 Directories                                  #
# **************************************************************************** #

SRC_DIR		= ./
INCLUDE_DIR	= ./
BUILD_DIR	= .build/
GNL_DIR		= gnl/
PRINTF_DIR	= printf/

# **************************************************************************** #
#                                 Directories                                  #
# **************************************************************************** #

FILES		+= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint
FILES		+= ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp
FILES		+= ft_strlen
FILES		+= ft_strlcpy ft_strlcat ft_toupper ft_tolower
FILES		+= ft_strchr ft_strrchr ft_strncmp ft_strnstr ft_atoi
FILES		+= ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim
FILES		+= ft_split ft_itoa
FILES		+= ft_strmapi ft_striteri
FILES		+= ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
FILES		+= ft_lstnew ft_lstadd_front ft_lstadd_back ft_lstsize
FILES		+= ft_lstlast ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

FILES		+= $(GNL_DIR)get_next_line
FILES		+= $(PRINTF_DIR)ft_printf $(PRINTF_DIR)ft_printf_utils

FILES		+= ft_strjoin_free ft_strndup

SRC			+= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS		+= $(addprefix $(BUILD_DIR), $(addsuffix .o, $(FILES)))

INCLUDE	= -I$(INCLUDE_DIR)

# **************************************************************************** #
#                                     Rules                                    #
# **************************************************************************** #

all: $(NAME)


$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@printf "$(ESC)$(B)$(C_GREEN)✔ LIBFT created successfully! $(ESC)$(RST)$@\n"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "\r$(ESC)$(C_YELLOW)✔ Compiled →$(ESC)$(RST) $< → $@$(ESC)$(RST)\n"

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		$(RM) "$(BUILD_DIR)"; \
		printf "\n$(ESC)$(B)$(C_MAGENTA)✔ Cleaned build directory$(ESC)$(RST)\n"; \
	fi
fclean: clean
	@if [ -f "$(NAME)" ] || [ -f "$(BONUS)" ]; then \
		$(RM) "$(NAME)"; \
		$(RM) "$(BONUS)"; \
		printf "\n$(ESC)$(B)$(C_RED)✔ Removed LIBFT$(ESC)$(RST)\n\n"; \
	fi
re: fclean all

.PHONY: all clean fclean re
