NAME = Bureaucrat
SRCS = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/PresidentialPardonForm.cpp src/RobotomyRequestForm.cpp src/ShrubberyCreationForm.cpp src/Intern.cpp
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