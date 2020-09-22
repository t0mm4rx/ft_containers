TARGET=main
FLAGS=-Wall -Werror -Wextra -g3 -fsanitize=address -std=c++98

SRC=${wildcard ./tests/*.cpp}
OBJ=${SRC:%.cpp=%.o}

all: ${TARGET}

./tests/%.o: ./tests/%.cpp
	clang++ ${FLAGS} -c $< -o $@

${TARGET}: ${OBJ}
	clang++ ${FLAGS} ${OBJ} -o ${TARGET}
	./${TARGET}

clean:
	rm -rf *.dSYM

fclean: clean
	rm -rf ${OBJ}
	rm -rf ${TARGET} ${TARGET}_test

re: fclean all

.PHONY: all ${TARGET} test