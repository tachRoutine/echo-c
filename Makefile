BINARY_NAME = "echo"

build:
	cc main.c -o $(BINARY_NAME)

run: build
	./$(BINARY_NAME) being awesome as usual -n