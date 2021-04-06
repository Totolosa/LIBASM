ERASE   = \033[2K\r
GREY    = \033[30m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
PINK    = \033[35m
CYAN    = \033[36m
WHITE   = \033[37m
END     = \033[0m
BOLD    = \033[1m
UNDER   = \033[4m
SUR     = \033[7m

NAME		= libasm.a

SRCS		=	ft_strlen.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s \
				
OBJS		= ${SRCS:.s=.o}

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address -g3

NASM			= nasm

ifeq ($(shell uname -s),Linux)
    ASMFLAGS	= -f elf64 -D__LINUX__=1
else
	ASMFLAGS	= -f macho64
endif

RM			= rm -f

all			: ${NAME}

%.o			: %.s libasm.h
			${NASM} ${ASMFLAGS} $< -o $@

${NAME}		: ${OBJS}
			ar rcs $@ $^
			echo "${GREEN}--> libasm.a generated <--${END}"
			
compil		: ${NAME}
			${CC} ${CFLAGS} -I. main.c ${NAME} -o libasm
			echo "${GREEN}--> libasm generated <--${END}"

clean		:
			${RM} ${OBJS}

fclean		: clean
			${RM} ${NAME}
			${RM} libasm
			echo "${RED}XXXXX CLEAN XXXXX${END}"

re			: fclean all

.PHONY: 	clean fclean all re compil 
.SILENT:	clean fclean all re compil ${OBJS} ${NAME}
