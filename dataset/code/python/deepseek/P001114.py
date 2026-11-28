Here's the Python code:

def solve(grid):
    R, C = len(grid), len(grid[0])
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    fresh = 1
    time = 0
    queue = [(i, j) for i in range(R) for j in range(C) if grid[i][j] == fresh]

    while queue:
        for _ in range(len(queue)):
            r, c = queue.pop(0)
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == fresh:
                    grid[nr][nc] = None
                    fresh -= 1
                    queue.append((nr, nc))
        time += 1

    if fresh == 0:
        return time - 1
    else:
        return -1

def main():
    R, C = map(int, input().split())
    grid = []
    for _ in range(R):
        row = list(map(int, input().split()))
        grid.append(row)
    print(solve(grid))

if __name__ == "__main__":
    main()

This code works by using a breadth-first search (BFS) strategy. We start by counting the number of fresh oranges and adding all of them to a queue. Then, while there are still fresh oranges, for each orange we have in the queue, we try to remove it and all its neighbors that are fresh oranges. If a neighbor becomes rotten, we mark it as such and add it to the queue. We increment the time by one for each round of removal.

Please note that this code does not handle the input properly if the input is not formatted correctly. In the given problem, the input is expected to be a grid of integers, where 1 represents fresh oranges and 0 represents empty cells.