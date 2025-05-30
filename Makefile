CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = programa

MAIN_SRC = main.c
METHODS_SRC = $(wildcard methods/*.c)

MAIN_OBJ = main.o
METHODS_OBJ = $(patsubst methods/%.c, methods/build/%.o, $(METHODS_SRC))
OBJS = $(MAIN_OBJ) $(METHODS_OBJ)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

methods/build/%.o: methods/%.c
	@if not exist "methods\\build" mkdir methods\\build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(MAIN_OBJ) $(TARGET) 2>nul
	@if exist methods\\build rmdir /S /Q methods\\build