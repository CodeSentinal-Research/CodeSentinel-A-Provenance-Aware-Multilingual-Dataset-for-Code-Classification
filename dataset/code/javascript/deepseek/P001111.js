Here is a JavaScript solution using Breadth-First Search (BFS):

function snakeAndLadder(n, l, ladder, s, snake) {
    let graph = Array.from({length: n+1}, () => []);

    for(let i = 0; i < ladder.length; i++) {
        graph[ladder[i][0]].push([ladder[i][1], 'L']);
    }

    for(let i = 0; i < snake.length; i++) {
        graph[snake[i][0]].push([snake[i][1], 'S']);
    }

    let distances = Array(n+1).fill(Infinity);
    distances[1] = 0;
    let queue = [1];

    while(queue.length !== 0) {
        let currentNode = queue.shift();

        for(let i = 1; i <= Math.min(n, currentNode+6); i++) {
            if(distances[currentNode + i] === Infinity) {
                distances[currentNode + i] = distances[currentNode] + 1;
                queue.push(currentNode + i);
            }

            if(graph[currentNode + i].length !== 0) {
                graph[currentNode + i].forEach(neighbor => {
                    if(neighbor[1] === 'L' && distances[neighbor[0]] === Infinity) {
                        distances[neighbor[0]] = distances[currentNode] + 1;
                        queue.push(neighbor[0]);
                    }
                });
            }
        }
    }

    return distances[n];
}

This script first builds the graph by creating a list of arrays for each cell (from 1 to N). It then creates a distances array with Infinity for all cells except the starting point, which is 0. A queue is then used to find the minimum number of dice throws to reach all cells.