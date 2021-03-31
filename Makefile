NAME		= libasm.a

SRCS		=	ft_strlen.s \
				
OBJS		= ${SRCS:.s=.o}

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

NASM			= nasm

ASMFLAGS	= -f macho64

RM			= rm -f

all			: ${NAME}

%.o			: %.s libasm.h
			${NASM} ${ASMFLAGS} ${SRCS}

${NAME}		: ${OBJS}
			ar rcs $@ $^
			
compil		: ${NAME}
			${CC} ${CFLAGS} main.c ${NAME} -o libasm

clean		:
			${RM} ${OBJS}

fclean		: clean
			${RM} ${NAME}
			${RM} libasm

re			: fclean all

.PHONY: 	clean fclean all re compil
