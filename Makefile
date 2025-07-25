# **************************************************************************** #
#                                  Project Name                                #
# **************************************************************************** #

NAME		= so_long
BONUS		= so_long_bonus

# **************************************************************************** #
#                             Compiler & Commands                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
AR			= ar rcs
RM			= rm -rf
MAKE		= make --no-print-directory
LOGO_BUILT	= 0
BONUS_BUILT	= 0

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
C_LOGO1		= 96m
C_LOGO2		= 91m
C_LOGO3		= 93m
C_LOGO4		= 92m
C_LOGO5		= 95m

# **************************************************************************** #
#                                 Directories                                  #
# **************************************************************************** #

VPATH		= src src_bonus

INCLUDE_DIR	= includes/
BUILD_DIR	= .build/
LIBS_DIR	= libs/
LIBFT_DIR	= $(LIBS_DIR)libft/
LIBFT_LIB	= $(LIBFT_DIR)libft.a
MLX_DIR		= $(LIBS_DIR)mlx/
MLX_LIB		= $(MLX_DIR)libmlx.a

# **************************************************************************** #
#                                    Files                                     #
# **************************************************************************** #

FILES		+= main
FILES		+= parser
FILES		+= flood_fill
FILES		+= render
FILES		+= images

BONUS_FILES		+= main
BONUS_FILES		+= parser
BONUS_FILES		+= flood_fill
BONUS_FILES		+= render
BONUS_FILES		+= images
BONUS_FILES		+= load
BONUS_FILES		+= loop
BONUS_FILES		+= enemy
BONUS_FILES		+= dead

SRC				= $(addsuffix .c, $(FILES))
BONUS_SRC		= $(addsuffix _bonus.c, $(BONUS_FILES))
OBJS			= $(addprefix $(BUILD_DIR), $(addsuffix .o, $(FILES)))
BONUS_OBJS		= $(addprefix $(BUILD_DIR), $(addsuffix _bonus.o, $(BONUS_FILES)))

INCLUDE	= -I$(INCLUDE_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

# **************************************************************************** #
#                                  Downloads                                   #
# **************************************************************************** #

MLX_URL	= https://cdn.intra.42.fr/document/document/36126/minilibx-linux.tgz

# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #

all: download $(NAME)
	@if [ "$(LOGO_BUILT)" = "1" ]; then \
		$(MAKE) logo; \
	else \
		echo "$(ESC)$(B)$(C_YELLOW)✔ Everything is up to date$(ESC)$(RST)"; \
	fi

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@
	@$(eval LOGO_BUILT := 1)
	@printf "$(ESC)$(B)$(C_GREEN)✔ Created binary: $(ESC)$(RST)$@\n"


$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "\r$(ESC)$(C_YELLOW)✔ Compiled →$(ESC)$(RST) $< → $@$(ESC)$(RST)\n"

$(MLX_LIB):
	@printf "$(ESC)$(C_YELLOW)◉ Building MiniLibX...$(ESC)$(RST)\n"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@printf "$(ESC)$(B)$(C_GREEN)✔ Created MiniLibX: $(ESC)$(RST)$@\n"

$(LIBFT_LIB):
	@printf "$(ESC)$(C_YELLOW)◉ Building Libft...$(ESC)$(RST)\n"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	@printf "$(ESC)$(B)$(C_GREEN)✔ Created Libft: $(ESC)$(RST)$@\n"

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		$(RM) "$(BUILD_DIR)"; \
		printf "\n$(ESC)$(B)$(C_MAGENTA)✔ Cleaned build directory$(ESC)$(RST)\n"; \
	fi
	@if [ -f "$(MLX_LIB)" ]; then \
		$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1; \
		printf "\n$(ESC)$(B)$(C_MAGENTA)✔ Cleaned build directory for MLX$(ESC)$(RST)\n"; \
	fi
	@if [ -f "$(LIBFT_LIB)" ]; then \
		$(MAKE) -C $(LIBFT_DIR) clean; \
		printf "\n$(ESC)$(B)$(C_MAGENTA)✔ Cleaned build directory for LIBFT$(ESC)$(RST)\n"; \
	fi

fclean: clean
	@if [ -d "$(MLX_DIR)" ]; then \
		$(RM) "$(MLX_DIR)"; \
		printf "\n$(ESC)$(B)$(C_RED)✔ Removed the $(MLX_DIR) directory$(ESC)$(RST)\n"; \
	fi
	@if [ -f "$(LIBFT_LIB)" ]; then \
		$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1; \
	fi
	@if [ -f "$(NAME)" ] || [ -f "$(BONUS)" ]; then \
		$(RM) "$(NAME)"; \
		$(RM) "$(BONUS)"; \
		printf "\n$(ESC)$(B)$(C_RED)✔ Removed binaries$(ESC)$(RST)\n\n"; \
	fi

re: fclean download
	@if [ -f $(BONUS) ]; then \
		printf "$(ESC)$(B)$(C_YELLOW)✔ Rebuilding Bonus$(ESC)$(RST)\n"; \
		$(MAKE) bonus; \
	else \
		printf "$(ESC)$(B)$(C_YELLOW)✔ Rebuilding regular build$(ESC)$(RST)\n"; \
		$(MAKE) all; \
	fi

download:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		mkdir -p $(dir $(MLX_DIR)); \
		wget -O /tmp/minilibx.tgz $(MLX_URL) > /dev/null 2>&1; \
		tar -xzf /tmp/minilibx.tgz -C $(MLX_DIR) --strip-components=1; \
		rm /tmp/minilibx.tgz; \
		printf "$(ESC)$(B)$(C_GREEN)✔ MiniLibX downloaded to $(MLX_DIR)$(ESC)$(RST)\n"; \
	fi

# **************************************************************************** #
#                                     Bonus                                    #
# **************************************************************************** #

bonus: download $(BONUS)
	@if [ "$(LOGO_BUILT)" = "1" ]; then \
		$(MAKE) logo; \
	else \
		echo "$(ESC)$(B)$(C_YELLOW)✔ Everything is up to date$(ESC)$(RST)"; \
	fi

$(BONUS): $(BONUS_OBJS) $(MLX_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@
	@$(eval LOGO_BUILT := 1)
	@printf "$(ESC)$(B)$(C_GREEN)✔ Created binary: $(ESC)$(RST)$@\n"

# **************************************************************************** #
#                                     Logo                                     #
# **************************************************************************** #

logo:
	@printf "\n \
	 $(ESC)$(C_LOGO1)       ___      $(ESC)$(C_LOGO2)      ___      $(ESC)$(C_LOGO3)      ___  $(ESC)$(C_LOGO2)      ___      $(ESC)$(C_LOGO4)      ___      $(ESC)$(C_LOGO5)      ___      \n \
	 $(ESC)$(C_LOGO1)      /  /\     $(ESC)$(C_LOGO2)     /  /\     $(ESC)$(C_LOGO3)     /  /\ $(ESC)$(C_LOGO2)     /  /\     $(ESC)$(C_LOGO4)     /  /\     $(ESC)$(C_LOGO5)     /  /\     \n \
	 $(ESC)$(C_LOGO1)     /  /::\    $(ESC)$(C_LOGO2)    /  /::\    $(ESC)$(C_LOGO3)    /  /:/ $(ESC)$(C_LOGO2)    /  /::\    $(ESC)$(C_LOGO4)    /  /::|    $(ESC)$(C_LOGO5)    /  /::\    \n \
	 $(ESC)$(C_LOGO1)    /__/:/\:\   $(ESC)$(C_LOGO2)   /  /:/\:\   $(ESC)$(C_LOGO3)   /  /:/  $(ESC)$(C_LOGO2)   /  /:/\:\   $(ESC)$(C_LOGO4)   /  /:|:|    $(ESC)$(C_LOGO5)   /  /:/\:\   \n \
	 $(ESC)$(C_LOGO1)   _\_ \:\ \:\  $(ESC)$(C_LOGO2)  /  /:/  \:\  $(ESC)$(C_LOGO3)  /  /:/   $(ESC)$(C_LOGO2)  /  /:/  \:\  $(ESC)$(C_LOGO4)  /  /:/|:|__  $(ESC)$(C_LOGO5)  /  /:/  \:\  \n \
	 $(ESC)$(C_LOGO1)  /__/\ \:\ \:\ $(ESC)$(C_LOGO2) /__/:/ \__\:\ $(ESC)$(C_LOGO3) /__/:/    $(ESC)$(C_LOGO2) /__/:/ \__\:\ $(ESC)$(C_LOGO4) /__/:/ |:| /\ $(ESC)$(C_LOGO5) /__/:/_\_ \:\ \n \
	 $(ESC)$(C_LOGO1)  \  \:\ \:\_\/ $(ESC)$(C_LOGO2) \  \:\ /  /:/ $(ESC)$(C_LOGO3) \  \:\    $(ESC)$(C_LOGO2) \  \:\ /  /:/ $(ESC)$(C_LOGO4) \__\/  |:|/:/ $(ESC)$(C_LOGO5) \  \:\__/\_\/ \n \
	 $(ESC)$(C_LOGO1)   \  \:\_\:\   $(ESC)$(C_LOGO2)  \  \:\  /:/  $(ESC)$(C_LOGO3)  \  \:\   $(ESC)$(C_LOGO2)  \  \:\  /:/  $(ESC)$(C_LOGO4)     |  |:/:/  $(ESC)$(C_LOGO5)  \  \:\ \:\   \n \
	 $(ESC)$(C_LOGO1)    \  \:\/:/   $(ESC)$(C_LOGO2)   \  \:\/:/   $(ESC)$(C_LOGO3)   \  \:\  $(ESC)$(C_LOGO2)   \  \:\/:/   $(ESC)$(C_LOGO4)     |__|::/   $(ESC)$(C_LOGO5)   \  \:\/:/   \n \
	 $(ESC)$(C_LOGO1)     \  \::/    $(ESC)$(C_LOGO2)    \  \::/    $(ESC)$(C_LOGO3)    \  \:\ $(ESC)$(C_LOGO2)    \  \::/    $(ESC)$(C_LOGO4)     /__/:/    $(ESC)$(C_LOGO5)    \  \::/    \n \
	 $(ESC)$(C_LOGO1)      \__\/     $(ESC)$(C_LOGO2)     \__\/     $(ESC)$(C_LOGO3)     \__\/ $(ESC)$(C_LOGO2)     \__\/     $(ESC)$(C_LOGO4)     \__\/     $(ESC)$(C_LOGO5)     \__\/     \n \
$(ESC)$(RST)\n"
	@printf "\
	                                                                       By: Miguel Azuaga\n"

# **************************************************************************** #
#                                   Phony Targets                              #
# **************************************************************************** #

.PHONY: all clean fclean re download logo