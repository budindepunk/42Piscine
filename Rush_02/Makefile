NAME=rush02
SRCS = build_arrays.c helper_functions.c helper_functions_2.c rush02.c
OBJS = ${SRC:.c=.o}
CC=cc
CFLAGS= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} -Iincludes ${FLAGS}

fclean:
	rm -f ${NAME}

re: fclean all