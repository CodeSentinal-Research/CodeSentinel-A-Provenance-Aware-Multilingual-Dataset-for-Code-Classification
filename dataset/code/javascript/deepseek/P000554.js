Here is a simple JavaScript solution using breadth-first search (BFS) algorithm. BFS is a graph traversing algorithm that explores all the vertices of a graph at the present depth before going to vertices at the next depth level.

function nearestExit(maze, entrance) {
    const m = maze.length;
    const n = maze[0].length;
    const queue = [[entrance[0], entrance[1], 0]];
    maze[entrance[0]][entrance[1]] = '+';

    while (queue.length) {
        const [x, y, steps] = queue.shift();

        if (x === 0 || x === m - 1 || y === 0 || y === n - 1) {
            return steps;
        }

        if (maze[x - 1] && maze[x - 1][y] !== '+') {
            maze[x - 1][y] = '+';
            queue.push([x - 1, y, steps + 1]);
        }

        if (maze[x][y - 1] !== '+') {
            maze[x][y - 1] = '+';
            queue.push([x, y - 1, steps + 1]);
        }

        if (maze[x + 1] && maze[x + 1][y] !== '+') {
            maze[x + 1][y] = '+';
            queue.push([x + 1, y, steps + 1]);
        }

        if (maze[x][y + 1] !== '+') {
            maze[x][y + 1] = '+';
            queue.push([x, y + 1, steps + 1]);
        }
    }

    return -1;
}

This function takes an maze and an entrance as input and returns the minimum number of steps to reach the nearest exit. The maze is represented as an m × n matrix where '.' represents an empty cell and '+' a wall. The entrance is represented by its coordinates (row and column). The function uses a queue to perform BFS, and for each step, it checks the adjacent cells. If any of the adjacent cells is an exit, it returns the number of steps. If no exit is found after checking all cells, it returns -1.