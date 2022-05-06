BIN_DIR = bin
BUILD_DIR = build
SRC_DIR = src
LDFLAGS=-lm

TARGET = $(BIN_DIR)/cparql

SRCS := $(shell find $(SRC_DIR) -name *.c)
OBJS := $(subst $(SRC_DIR), $(BUILD_DIR), $(SRCS:%.c=%.o))
VPATH := $(SRC_DIR):$(BUILD_DIR)

all: $(TARGET)

$(TARGET): $(OBJS)
	gcc -g -Wall -o $(LDFLAGS) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: %.c
	gcc -g -Wall -g -c $< -o $@

.PHONY: clean all

clean:
	rm $(BUILD_DIR)/*.o $(TARGET)
