CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	$(wildcard ./*.cpp)

RMIF	=	rm -f

OBJ		=	${SRCS:.cpp=.o}

.cpp.o:
	@${CC} ${CFLAGS}  -c $< -o ${<:.cpp=.o}

all:	${OBJ}
	${CC} ${CFLAGS} ${OBJ}

clean:
		   	${RMIF} ${OBJ}

fclean:		clean
			${RMIF} a.out

re:			fclean all

.PHONY:		all clean fclean rm
