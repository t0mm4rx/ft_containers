TARGET=main

all: ${TARGET}

${TARGET}:
	clang++ -Werror -Wextra -Wall -fsanitize=address -g3 main.cpp -o ${TARGET}
	./${TARGET}

test:
	clang++ -fsanitize=address -g3 main_test.cpp -o ${TARGET}_test
	./${TARGET}_test

clean:
	rm -rf *.dSYM

fclean: clean
	rm -rf ${TARGET} ${TARGET}_test

re: fclean all

.PHONY: all ${TARGET} test