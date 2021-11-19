FLAGS		=	-Wall -Wextra -Werror --std=c++98

ITERATORS	=	./containers/iterators/random_access_iterator.hpp \
				./containers/iterators/reverse_iterator.hpp \
				./containers/iterators/utils.hpp

CONTAINERS	=	./containers/vector.hpp \
				./containers/headers.hpp

INC			=	${ITERATORS} ${CONTAINERS} ./tests/tests.hpp

SRCS		=	./tests/main.cpp \
				./tests/VectorTest.cpp \

OBJ			=	$(SRCS:.cpp=.o)

NAME		=	allTests

%.o: %.cpp $(INC)
	clang++ $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean