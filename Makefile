CC 	= gcc
CFLAGS = -std=c11 -Wall -Wextra -Iinclude
TESTFLAGS = -g -O0 -fsanitize=address,undefined

SRC = $(wildcard src/*/*.c)
TESTS = $(wildcard tests/*.c)

build:
		mkdir -p build

test: $(SRC) $(TESTS) | build
	$(CC) $(CFLAGS) $(TESTFLAGS) $^ -o build/run_tests
	./build/run_tests

.PHONY: test