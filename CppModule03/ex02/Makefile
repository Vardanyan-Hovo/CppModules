NAME	=	Repetitivework

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	$(wildcard ./*.cpp)

RMIF	=	rm -f

OBJ		=	${SRCS:.cpp=.o}

.cpp.o: 
	@${CC} ${CFLAGS}  -c $< -o ${<:.cpp=.o}

all:		${NAME}

${NAME}:	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
		   	${RMIF} ${OBJ}

fclean:		clean
			${RMIF} ${NAME}

re:			fclean all

.PHONY:		all clean fclean rm
