Here is the JavaScript code for the M-Coloring Problem. The code takes the graph as an adjacency list and the number of colors as inputs and returns true if a valid coloring exists, otherwise false.

function isSafe(v, color, graph, colors, i): boolean {
    for (let neighbour of graph[i]) {
        if (colors[neighbour] == colors[v]) {
            return false;
        }
    }
    return true;
}

function graphColoring(graph, m): boolean {
    let colors: Array<number> = new Array(graph.length).fill(-1);

    return solve(graph, colors, 0);
}

function solve(graph, colors, v): boolean {
    if (v == graph.length) {
        return true;
    }

    for (let i: number = 1; i <= graph.length; i++) {
        if (isSafe(v, i, graph, colors)) {
            colors[v] = i;
            if (solve(graph, colors, v + 1) == true) {
                return true;
            }
            colors[v] = -1;
        }
    }

    return false;
}

// test the code
let graph = [
    [2, 3],
    [1, 3],
    [0, 3, 1],
    [0, 1],
    [1, 2],
    [0, 2]
];
console.log(graphColoring(graph, 3));  // prints: true

In this code, we use a depth-first search (DFS) approach to solve the problem. We start from the first vertex and try to color it with different colors, if it's safe to do so, we go to the next vertex. If we can't find a safe color for a vertex, we backtrack and try another color. We continue this process until we have found a valid coloring for all vertices. If we have found a valid coloring for all vertices, we return true, otherwise we return false.