# Smart-Delivery-System

1️⃣ Project Overview

The Smart Delivery System is a C-based program that helps determine the shortest delivery route between cities in a network.
It models cities as nodes and roads as edges in a graph and uses Dijkstra’s algorithm to calculate the fastest route.

Key Features:

Input a list of cities and the roads connecting them.

Automatically calculate the shortest path between a source city and a destination city.

Display the path taken and the total distance.

Use Case Example:
A delivery company wants to send a package from Delhi to Mumbai.
The program will tell the best route, e.g., Delhi -> Jaipur -> Agra -> Mumbai and the total distance.

2️⃣ How the Project Works (File Roles)
File	Role	Future Improvements
graph.h	Declares constants and functions for graph operations (initializeGraph(), addEdge(), dijkstra()).	Add new function prototypes like addCity(), loadGraphFromFile().
graph.c	Implements graph functions: sets up adjacency matrix, adds roads, calculates shortest paths using Dijkstra’s algorithm.	Support directed graphs, floating-point weights, implement other shortest path algorithms, modularize Dijkstra.
main.c	Handles user input for cities, roads, start and destination; calls graph functions; displays results.	Add menu system, input validation, load/save data from files, handle multiple deliveries.
Makefile	Compiles the program (make) and removes executable (make clean).	Add make run to compile & execute, make cross-platform.
3️⃣ Current Workflow

User enters number of cities and their names.

User enters number of roads and distance between cities.

User enters start and destination city.

Program calculates shortest path using Dijkstra’s algorithm.

Program outputs:

Path of cities to follow.

Total distance.



4️⃣ Future Enhancements

User Interface Improvements: Menu-driven system, color-coded output.

Graph Improvements: Directed/weighted graphs, dynamic memory.

Algorithmic Enhancements: Multiple destination optimization, other shortest path algorithms.

Data Storage: Load/save cities and roads from text files.

Advanced Features: Multiple deliveries, cost/time optimization, ASCII map or GUI visualization.



5️⃣ Benefits

Efficiency: Quickly finds optimal delivery routes.

Flexibility: Easily extendable to include more cities or different algorithms.

Practical Application: Useful for logistics, courier services, and delivery planning.