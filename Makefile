TARGET := main

SRC := src
INC := include
BIN := bin
TEST := test
BUILD := build

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %, $(BUILD)/%, $(notdir $(SOURCE:.c=.o)))


CC = gcc
CFLAGS = -Wall -I$(INC) -std=c11

# $@ evaluates to 'target' bin/main $(BIN)/$(TARGET)
# $^ evaluates to 'dependency' $(OBJECT)
$(BIN)/$(TARGET): src/run.c src/compilation.c
	$(CC) $(CFLAGS) -o $@ src/run.c -lm

# $< evaluates to first name in 'dependencies' $(SRC)/%.c
$(BUILD)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# avoid doing something to file named clean
.PHONY: clean

clean:
	rm -f build/*.o bin/*
