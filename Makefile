CC = gcc
#CFLAGS = -Wall -Wextra -std=c11 -O2 -g -mavx2
CFLAGS = -O2 -mavx2 -std=gnu17
INCLUDES = -Isrc
LDFLAGS = -lm -lX11 -lpng -lasound

SRC_DIR = src
BUILD_DIR = build
CODE_DIR = code

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

TARGET = $(BUILD_DIR)/Main

all:
	$(CC) $(CFLAGS) $(INCLUDES) ./$(SRC_DIR)/Main.c -o ./$(TARGET) $(LDFLAGS) 

exe:
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)/*

dg: clean
	$(CC) $(CFLAGS) -g $(INCLUDES) ./$(SRC_DIR)/Main.c -o ./$(TARGET) $(LDFLAGS)
	gdb ./$(TARGET)

do: clean all exe