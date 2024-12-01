NAME = HiThisIsBrain
SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}
INCS = includes
CC = c++
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o} -I ${INCS}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re