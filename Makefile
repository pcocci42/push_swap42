### COMPILATION ###
CC      = gcc 
FLAGS  = -Wall -Wextra -Werror

### EXECUTABLE ###
NAME   = push_swap

### INCLUDES ###
LIBFT  = libft
OBJ_PATH  = objs
HEADER = includes
SRC_PATH  = srcs
BONUS_PATH = bonus

### SOURCE FILES ###
SOURCES = main.c \
	push.c	\
	reverse_rotate.c	\
	rotate.c	\
	swap.c	\
	sort_3.c	\
	push_back.c	\
	correct.c	\
	complex_sort_a.c	\
	complex_sort_b.c	\
	parse_argument.c	\
	atoi.c	\
	check_argument.c

BONUS = bonus/checker.c ./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c \
		bonus/checks.c bonus/utils.c bonus/parse.c bonus/fill_normal.c bonus/ft_str.c bonus/do_op.c bonus/utils_2.c
### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

UTILS_OBJ = $(addprefix $(SRCS_PATH)/$(BONUS_UTILS:.c=.o))
BONUS_OBJ = $(BONUS:.c=.o)

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: lib tmp $(NAME) bonus

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -lft -o $@ $^ 
	@echo "$(GREEN)Project successfully compiled"

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c   $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

$(BONUS_PATH)/%.o : $(BONUS_PATH)/%.c $(HEADER)/$(NAME).h
	$(CC) $(FLAGS) -c -o $@ $<

bonus:	$(BONUS_OBJ) 
	$(CC) $(FLAGS) $(BONUS_OBJ) srcs/push.c srcs/reverse_rotate.c srcs/rotate.c srcs/swap.c -L $(LIBFT) -o checker


clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@rm -f $(BONUS_OBJ)
	@rm -f $(BONUS_PATH/%.o)
	@rm -f checker
	@make fclean -C $(LIBFT)

re: fclean
	@$(MAKE) all 

.PHONY: temporary, re, fclean, clean, bonus