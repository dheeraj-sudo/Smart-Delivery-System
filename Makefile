CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/graph.c
OUT = planner.exe

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

clean:
	del $(OUT)
