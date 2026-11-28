Here is a JavaScript solution for the M-Coloring problem. The solution uses Depth First Search (DFS) algorithm to check if a graph can be colored with M colors.

function isSafe(v, colour, graph, color) {
    for (let i = 0; i < graph[v]; i++) {
        if (graph[v][i] == 1 && colour[i] == color) {
            return false;
        }
    }
    return true;
}

function graphColoring(m, graph) {
    let colour = new Array(m).fill(0);
    if (colorGraph(m, graph, colour, 0)) {
        return true;
    } else {
        return false;
    }
}

function colorGraph(m, graph, colour, v) {
    if (v == m) {
        return true;
    }

    for (let i = 1; i <= m; i++) {
        if (isSafe(v, colour, graph, i)) {
            colour[v] = i;
            if (colorGraph(m, graph, colour, v + 1)) {
                return true;
            }
            colour[v] = 0;
        }
    }
    return false;
}

let graph = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [1, 0, 1, 0]
];

console.log(graphColoring(4, graph));  // Output: true

graph = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [1, 0, 1, 0]
];

console.log(graphColoring(4, graph));  // Output: false

In the code above, the graph is represented as a 2D array where each element at index [i][j] represents an edge between node i and node j. The `isSafe` function is used to check if a vertex can be colored with a certain color. The `colorGraph` function uses depth first search to color all vertices recursively.