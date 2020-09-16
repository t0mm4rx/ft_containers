TARGET=main
FLAGS=-Wall -Werror -Wextra -g3 -fsanitize=address

SRC=${wildcard ./tests/*.cpp}
OBJ=${SRC:%.cpp=%.o}

all: ${TARGET}

./tests/%.o: ./tests/%.cpp
	clang++ ${FLAGS} -c $< -o $@

${TARGET}: ${OBJ}
	clang++ ${FLAGS} ${OBJ} -o ${TARGET}
	./${TARGET}

test:
	clang++ -fsanitize=address -g3 main_test.cpp -o ${TARGET}_test
	./${TARGET}_test

clean:
	rm -rf *.dSYM

fclean: clean
	rm -rf ${OBJ}
	rm -rf ${TARGET} ${TARGET}_test

re: fclean all

.PHONY: all ${TARGET} test