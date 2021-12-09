FLAGS		=	-Wall -Wextra -Werror --std=c++98

ITERATORS	=	contaiters/iterators/random_access_iterator.hpp \
				contaiters/iterators/reverse_iterator.hpp \
				contaiters/iterators/utils.hpp \
				containers/iterators/binary_search_tree.hpp \
				containers/iterators/binary_search_tree_iterator.hpp

CONTAINERS	=	containers/vector.hpp \
				containers/stack.hpp \
				containers/headers.hpp

INC			=	${ITERATORS} ${CONTAINERS} ./tests/tests.hpp

SRCS		=	tests/main.cpp \
				tests/leaksTest.cpp \
				tests/VectorTest.cpp \
				tests/StackTest.cpp \
				tests/UtilsTests.cpp \
				tests/MapTest.cpp

OBJ			=	$(SRCS:.cpp=.o)

NAME		=	allTests

%.o: %.cpp $(INC)
	clang++ $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) -g -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean