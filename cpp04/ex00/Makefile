NAME = Animal
SRCS = src/main.cpp src/Animal.cpp src/Dog.cpp src/Cat.cpp src/WrongCat.cpp src/WrongAnimal.cpp
OBJS = ${SRCS:.cpp=.o}
CC = c++
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re