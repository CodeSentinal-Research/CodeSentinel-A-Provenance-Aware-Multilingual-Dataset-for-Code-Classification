Sure, here is a simple implementation of Prim's algorithm in JavaScript. This script reads input from stdin and writes the minimum spanning tree's weight to stdout.

process.stdin.setEncoding('utf-8');

process.stdin.on('data', function(data) {
    var arr = data.split('\n');
    var N = parseInt(arr[0]);
    var graph = [];
    for (var i = 1; i < arr.length; i++) {
        var u = parseInt(arr[i].split(' ')[0]);
        var v = parseInt(arr[i].split(' ')[1]);
        var w = parseInt(arr[i].split(' ')[2]);
        if (u === v) {
            continue;
        }
        graph[u] = graph[u] || [];
        graph[u][v] = w;
        graph[v] = graph[v] || [];
        graph[v][u] = w;
    }

    var visited = new Array(N + 1).fill(false);
    visited[1] = true;
    var minWeight = 0;

    while (Object.keys(graph).length > 0) {
        var minCost = Infinity;
        var u, v;
        for (u in graph) {
            for (v in graph[u]) {
                if (visited[u] && visited[v] || !visited[u] && !visited[v]) {
                    continue;
                }
                if (minCost > graph[u][v]) {
                    minCost = graph[u][v];
                    minWeight += minCost;
                    visited[u] = true;
                    visited[v] = true;
                }
            }
        }
    }

    console.log(minWeight);
});
This script reads a list of pairs of integers from stdin, and uses the Prim's algorithm to find the minimum spanning tree of the graph. It then prints the total weight of the tree to stdout.

Please note that this is a simple implementation and may not be efficient for large inputs. The time complexity of Prim's algorithm is O(|V|²), where |V| is the number of vertices.