function solve(N, E, M, edges) {
    // Convert edges list into adjacency list
    let adjList = Array.from({length: N}, () => []);
    for (let [u, v] of edges) {
        adjList[u - 1].push(v - 1);
        adjList[v - 1].push(u - 1);
    }

    // Check if graph is bicolorable
    let colors = Array(N).fill(-1);
    function isBicolorable(node, color) {
        colors[node] = color;
        for (let neighbor of adjList[node]) {
            if (colors[neighbor] == color) {
                return false;
            }
            if (colors[neighbor] == -1 && !isBicolorable(neighbor, 1 - color)) {
                return false;
            }
        }
        return true;
    }

    for (let node = 0; node < N; node++) {
        if (colors[node] == -1 && !isBicolorable(node, 0)) {
            return "NO";
        }
    }
    return "YES";
}

let [N, E, M] = [5, 4, 2];
let edges = [[1, 2], [1, 3], [2, 4], [3, 4]];
console.log(solve(N, E, M, edges));