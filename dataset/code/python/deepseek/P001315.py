Here is the Python code for the problem:

def find_path(maze, x, y, path):
    if x == y == N - 1:
        print(' -> '.join(path))
        return

    if 0 <= x - 1 and maze[x - 1][y] == 1:
        path.append('up')
        find_path(maze, x - 1, y, path)
        path.pop()

    if 0 <= x + 1 and maze[x + 1][y] == 1:
        path.append('down')
        find_path(maze, x + 1, y, path)
        path.pop()

    if 0 <= y - 1 and maze[x][y - 1] == 1:
        path.append('left')
        find_path(maze, x, y - 1, path)
        path.pop()

    if 0 <= y + 1 and maze[x][y + 1] == 1:
        path.append('right')
        find_path(maze, x, y + 1, path)
        path.pop()

def main():
    global N
    N = int(input())
    maze = []

    for i in range(N):
        maze.append(list(map(int, input().split())))

    find_path(maze, 0, 0, [])

if __name__ == "__main__":
    main()

This code will print out all the possible paths from the top-left corner to the bottom-right corner in lexicographical order. The `find_path` function is a recursive function that takes the maze, current coordinates, the path so far, and the path itself as parameters. It checks all four possible directions (up, down, left, right) and if it can move in a direction, it makes a move in that direction and recurses. When it reaches the destination, it prints the path.