CC = gcc
CFLAGS = -Iinclude

SRC = src/main.c src/graph.c src/Display_Map.c src/Dijkstra.c src/Project.c 

OUT = planner.exe

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

clean:
	del $(OUT)
