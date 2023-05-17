NAME	=	Array

CPP		=	c++

CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	$(wildcard ./*.cpp)


HEADERS = $(wildcard *.hpp) $(wildcard *.tpp)

RMIF	=	rm -f

OBJ		=	${SRCS:.cpp=.o}

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

all:		${NAME}

${NAME}:	${OBJ}
	${CPP} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean:
		   	${RMIF} ${OBJ}

fclean:		clean
			${RMIF} ${NAME}

re:			fclean all

.PHONY:		all clean fclean rm
