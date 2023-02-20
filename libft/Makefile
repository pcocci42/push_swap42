CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFT = includes/libft.h
FTP = includes/ft_printf.h

OBJDIR = objs

NAME = libft.a

SRC_IS = \
	ft_isalnum.c	ft_isaplha.c	ft_isascii.c	ft_isdigit.c	\
	ft_isprint.c	\

SRC_LST = \
	ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c	ft_lstdelone.c	\
	ft_lstiter.c	ft_lstlast.c	ft_lstmap.c	ft_lstnew.c	ft_lstsize.c	\

SRC_MEM = \
	ft_bzero.c	ft_calloc.c	ft_memchr.c	ft_memcmp.c	ft_memcpy.c	ft_memmove.c	ft_memset.c	\

SRC_PRINTF = \
	char_process.c	counters.c	ft_printf.c	hex_helper.c	hex_process.c	\
	nb_process_u.c	nb_process.c	nbr_helper.c	percent_process.c	\
	ptr_process.c	str_process.c	\

SRC_STR = \
	ft_atoi.c	ft_itoa.c	ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	\
	ft_split.c	ft_strchr.c	ft_strdup.c	ft_striteri.c	ft_strjoin.c	ft_strlcat.c	\
	ft_strlcpy.c	ft_strlen.c	ft_strmapi.c	ft_strncmp.c	ft_strnstr.c	ft_strrchr.c	\
	ft_strtrim.c	ft_substr.c	ft_tolower.c	ft_toupper.c	\

OBJ_IS = $(addprefix ${OBJDIR}/, $(SRC_IO:.c=.o))

OBJ_LST = $(addprefix ${OBJDIR}/, $(SRC_LST:.c=.o))

OBJ_MEM = $(addprefix ${OBJDIR}/, $(SRC_MEM:.c=.o))

OBJ_PRINTF = $(addprefix ${OBJDIR}/, $(SRC_PRINTF:.c=.o))

OBJ_STR = $(addprefix ${OBJDIR}/, $(SRC_STR:.c=.o))

all: ${NAME}
	@echo Success "	" [${NAME}]

${NAME} : ${OBJ_IS} ${OBJ_LST} ${OBJ_MEM} ${OBJ_PRINTF} ${OBJ_STR}
	@ar rcs ${NAME} ${OBJ_IS} ${OBJ_LST} ${OBJ_MEM} ${OBJ_PRINTF} ${OBJ_STR}
	@echo Compiling [${NAME}]...

${OBJDIR}/%.o : ./srcs/ft_is/%.c ${LFT}
	@echo Compiling [$@]...
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<

${OBJDIR}/%.o : ./srcs/ft_lst/%.c ${LFT}
	@echo Compiling [$@]...
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<

${OBJDIR}/%.o : ./srcs/ft_mem/%.c ${LFT}
	@echo Compiling [$@]...
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<

${OBJDIR}/%.o : ./srcs/ft_printf/%.c ${FTP}
	@echo Compiling [$@]...
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<

${OBJDIR}/%.o : ./srcs/ft_str/%.c ${LFT}
	@echo Compiling [$@]...
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./includes -c -o $@ $<

clean:
	@echo Cleaning"  "[${OBJDIR}]...
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo Cleaning"  "[${NAME}]...
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

