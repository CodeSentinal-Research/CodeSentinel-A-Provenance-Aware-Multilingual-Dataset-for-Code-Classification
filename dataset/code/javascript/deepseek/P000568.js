Here is a JavaScript solution using a Breadth First Search (BFS) algorithm. The BFS algorithm is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key') and explores the neighbor nodes at the present depth, before moving on to nodes at the next depth level.

const queue = [{x: 0, y: 0, count: 0}];
const visited = new Set([`${0},${0}`]);

function bfs() {
    while (queue.length) {
        const {x, y, count} = queue.shift();
        if (`${x},${y}` === `${target.x},${target.y}`) {
            return count;
        }
        for (let i = 0; i < 8; i++) {
            const nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny)) {
                queue.push({x: nx, y: ny, count: count + 1});
                visited.add(`${nx},${ny}`);
            }
        }
    }
}

function isValid(x, y) {
    return x >= 0 && x < N && y >= 0 && y < N && !visited.has(`${x},${y}`);
}

const N = 300;
const dx = [2, 2, -2, -2, 1, 1, -1, -1];
const dy = [1, -1, 1, -1, 2, -2, 2, -2];

In this code, `N` is the size of the board, and `dx` and `dy` are the eight possible movements of the knight. We use a queue to perform the BFS, and a `Set` to keep track of visited nodes. The BFS starts from the knight's starting position (0, 0) and explores all possible knight moves until it reaches the target.

You should call the `bfs` function to start the BFS and get the minimum number of moves. For example, to get the minimum number of moves to reach the cell (3, 3), you would call `bfs({x: 0, y: 0, count: 0})`.