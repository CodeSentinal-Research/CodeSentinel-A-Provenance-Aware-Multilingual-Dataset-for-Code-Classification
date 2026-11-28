Here is the JavaScript code for the given problem:

function minimumBuses(routes, source, target) {
    let graph = new Map();
    let visited = new Set();
    let minBuses = Infinity;

    // Build the graph based on the routes
    for (let i = 0; i < routes.length; i++) {
        for (let j = 0; j < routes[i].length - 1; j++) {
            if (!graph.has(routes[i][j])) {
                graph.set(routes[i][j], new Set());
            }
            graph.get(routes[i][j]).add(routes[i][j+1]);
        }
        graph.get(routes[i][routes[i].length-1]).add(routes[i][0]);
    }

    // Traverse from source to target and find the shortest path
    function dfs(start, end, routeCount) {
        if (start === end) {
            minBuses = Math.min(minBuses, routeCount);
            return;
        }

        if (routeCount >= minBuses) {
            return;
        }

        for (let nextStop of graph.get(start)) {
            dfs(nextStop, end, routeCount + 1);
        }
    }

    dfs(source, target, 0);

    // If it's impossible to reach the target, return -1
    if (minBuses === Infinity) {
        return -1;
    }

    return minBuses;
}
This code first builds the graph based on the routes. The graph is represented as a map where each key is a bus stop, and the value is a set of bus stops reachable from the key stop. Then it uses a depth-first search (DFS) to find the shortest path from the source to the target.