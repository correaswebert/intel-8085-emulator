TARGET := main

SRC := src
INC := include
BIN := bin
TEST := test
BUILD := build

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %, $(BUILD)/%, $(notdir $(SOURCE:.c=.o)))


CC = gcc
CFLAGS = -I$(INC) -std=c11

# $@ evaluates to 'target' bin/main $(BIN)/$(TARGET)
# $^ evaluates to 'dependency' $(OBJECT)
$(BIN)/$(TARGET): $(OBJECT) rc cc
	$(CC) $(CFLAGS) -o $@ src/run.c -lm

# $< evaluates to first name in 'dependencies' $(SRC)/%.c
$(BUILD)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# write code (in hex)
wc: src/writecode.c
	$(CC) $(CFLAGS) $^ -lm -o $(BIN)/$@

# read code (in hex and asm)
rc: src/readcode.c
	$(CC) $(CFLAGS) $^ -lm -o $(BIN)/$@

# convert asm to hex
cc: src/tokenizer.c
	$(CC) $(CFLAGS) $^ -lm -o $(BIN)/$@

# avoid doing something to file named clean
.PHONY: clean

clean:
	rm -f build/*.o bin/* codes/*.mc
