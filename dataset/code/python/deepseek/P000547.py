Here's the Python code for the problem:

from typing import List

def max_minutes(m: int, n: int, grid: List[List[int]]) -> int:
    queue = [(0, 0, 0)]
    visited = set([(0, 0)])
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    while queue:
        minutes = queue.pop(0)
        x, y = minutes[0], minutes[1]

        if [x, y] == [m - 1, n - 1]:
            return minutes[2]

        for direction in directions:
            new_x, new_y = x + direction[0], y + direction[1]
            if 0 <= new_x < m and 0 <= new_y < n and grid[new_x][new_y] == 0 and (new_x, new_y) not in visited:
                queue.append((new_x, new_y, minutes[2] + 1))
                visited.add((new_x, new_y))

    return -1

def main():
    m, n = 5, 5
    grid = [[0, 0, 0, 0, 0], [0, 1, 0, 1, 0], [0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0]]
    result = max_minutes(m, n, grid)
    print(result)  

if __name__ == "__main__":
    main()

In this code, we use a Breadth-First Search (BFS) approach to solve the problem. We start from the top-left cell and explore all adjacent cells that are empty or walls until we reach the bottom-right cell. Each step, we update the number of minutes and add all new cells that we can reach in the next step to the queue. If we reach the destination, we return the number of minutes. If we can't reach the destination, we return -1.

The main function is just for testing the code. It initializes the grid and calls the max_minutes function, then prints the result.