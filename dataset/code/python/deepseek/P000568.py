Here is the Python code for the problem:

from collections import deque

def minimumMoves(x, y):
    start = (0, 0, 0)
    target = (x, y, 0)
    if x == y:
        return max(abs(x - target[0]), abs(y - target[1]))

    queue = deque([(start, start[2])])
    visited = {start}

    while queue:
        curr_pos, step = queue.popleft()
        if curr_pos == target:
            return step
        for direction in [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]:
            new_pos = (curr_pos[0] + direction[0], curr_pos[1] + direction[1], step + 1)
            if (0 <= new_pos[0] <= 300 and 0 <= new_pos[1] <= 300 and
                new_pos not in visited):
                visited.add(new_pos)
                queue.append((new_pos, step + 1))

def main():
    x, y = map(int, input().split())
    print(minimumMoves(x, y))

if __name__ == "__main__":
    main()

This program uses a breadth-first search strategy to find the minimum number of moves required by the knight to reach the target cell. It starts from the position (0,0) with no moves yet, and then moves in all possible directions (up, down, left, right, up & down diagonally, and up & down one step at a time). The visited list is used to ensure that we don't visit the same cell more than once. The program takes input as x and y coordinates and outputs the minimum number of moves required by the knight.