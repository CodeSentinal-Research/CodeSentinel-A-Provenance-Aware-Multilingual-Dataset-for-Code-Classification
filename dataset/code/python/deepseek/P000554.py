Here is a Python solution for the problem. The solution uses a Breadth-First Search (BFS) algorithm. BFS is a graph traversal algorithm that explores all the adjacent vertices of a vertex before moving to its adjacent vertices. In this case, the maze is represented as a graph with cells as vertices and the '+' cells as edges, and the entrance as the starting vertex.

from collections import deque

def nearestExit(maze, entrance):
    m, n = len(maze), len(maze[0])
    visited = [[False]*n for _ in maze]
    moves = [(0,1), (0,-1), (1,0), (-1,0)]
    q = deque([(entrance, 0)])
    visited[entrance[0]][entrance[1]] = True

    while q:
        (x, y, steps) = q.popleft()
        if (x, y) != entrance and (x, y, steps) not in visited:
            visited[x][y] = True
            if (x == 0 or x == m-1 or y == 0 or y == n-1) and (x, y) not in [(a, b) for a in range(m) for b in range(n)]:
                return steps + 1
            for dx, dy in moves:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and maze[nx][ny] == '.':
                    q.append(((nx, ny, steps+1)) )
    return -1

The main function is as follows:

if __name__ == '__main__':
    maze = [['+', '+', '.', '+', '+'],
            ['.', '.', '.', '.', '+'],
            ['.', '.', '.', '.', '+'],
            ['.', '+', '+', '+', '.'],
            ['.', '+', '.', '.', '+']]
    entrance = (2, 2)
    print(nearestExit(maze, entrance))

This program first initializes a maze and an entrance. Then, it calls the `nearestExit` function with the maze and entrance as arguments. The program then prints the result of the call.

The `nearestExit` function takes as arguments the maze and entrance, then initializes the visited array to keep track of visited cells. It also initializes the queue with the entrance and the number of steps to reach it. The function then enters a loop that continues until the queue is empty. On each iteration of the loop, it pops a cell from the queue and checks if it is the entrance or a cell on the boundary, and if it is not visited. If so, it checks all four possible moves (up, down, left, right) for each cell, and if it finds a cell that is not visited and is not the entrance, it adds it to the queue with the number of steps plus one. If no empty cell on the boundary is found, it returns -1. If a cell is found, it returns the number of steps.