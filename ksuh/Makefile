CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = checker.c ft_strlen.c get_next_line.c

OBJS = ${SRCS:.c=.o}

NAME = checker

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
