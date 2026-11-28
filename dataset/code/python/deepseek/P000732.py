Here is the Python code for your problem:

def find_paths(maze, row, col, path):
    if row == len(maze) - 1 and col == len(maze[0]) - 1:
        print(''.join(path))
        return

    if row < len(maze) - 1 and maze[row + 1][col] == 1:
        path.append('D')
        find_paths(maze, row + 1, col, path)
        path.pop()

    if row < len(maze) - 1 and col < len(maze[0]) - 1 and maze[row + 1][col + 1] == 1:
        path.append('RD')
        find_paths(maze, row + 1, col + 1, path)
        path.pop()

    if col < len(maze[0]) - 1 and maze[row][col + 1] == 1:
        path.append('R')
        find_paths(maze, row, col + 1, path)
        path.pop()

    if row < len(maze) - 1 and maze[row + 1][col] == 1 and col < len(maze[0]) - 1 and maze[row + 1][col + 1] == 1:
        path.append('DR')
        find_paths(maze, row + 1, col + 1, path)
        path.pop()

def solve(maze):
    path = []
    find_paths(maze, 0, 0, path)

maze = [
    [1, 0, 0],
    [1, 1, 0],
    [1, 1, 1]
]
solve(maze)

This code will print all possible paths from top left to bottom right in lexicographical order. The 'D' represents moving down, 'R' represents moving right and 'DR' represents moving diagonally down right.

For input handling, we can take the input from the user. Here is how you can do it:

def get_input():
    N = int(input("Enter N: "))
    maze = []
    for i in range(N):
        maze.append(list(map(int, input("Enter row {}: ".format(i + 1)).split())))
    return maze

def main():
    maze = get_input()
    solve(maze)

if __name__ == "__main__":
    main()

This code will prompt the user to enter N and then enter each row of the maze. The entered maze will be used to solve the problem.