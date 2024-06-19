NAME = hash.a

SRCS =	create_hash.c \
		free_hash.c \
		insert_hash.c \
		search_hash.c \
		resize_hash.c \

OBJS = ${SRCS:.c=.o}

HEAD = hash.h

AR = ar rcs
RM = rm -rf
LIB = ranlib

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re