NAME	=	Formupmaggots

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	$(wildcard ./*.cpp)


HEADERS = $(wildcard *.hpp)

RMIF	=	rm -f

OBJ		=	${SRCS:.cpp=.o}

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all:		${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
		   	${RMIF} ${OBJ}

fclean:		clean
			${RMIF} ${NAME}

re:			fclean all

.PHONY:		all clean fclean rm
