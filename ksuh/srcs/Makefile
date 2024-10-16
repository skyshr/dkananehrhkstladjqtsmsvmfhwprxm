CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = error.c init_utils.c init_validation.c init.c main.c \
		print.c solve_utils.c solve_validation.c solve.c

OBJS = ${SRCS:.c=.o}

NAME = rush-01

all : ${NAME}

${NAME} : ${OBJS} 
	${CC} ${CFLAGS} -o $@ $^

%.o : %.c
	${CC} ${CFLAGS} -c $<

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re
