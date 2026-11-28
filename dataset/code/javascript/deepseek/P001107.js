Here is a JavaScript solution for the problem:

function transitiveClosureGraph(input) {
    let [N, M] = input[0].split(' ').map(Number);
    let graph = new Array(N).fill(0).map(() => new Array(N).fill(0));

    for(let i = 0; i < M; i++) {
        let [u, v] = input[i + 1].split(' ').map(Number);
        graph[u][v] = 1;
    }

    for(let k = 0; k < N; k++) {
        for(let i = 0; i < N; i++) {
            for(let j = 0; j < N; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }

    for(let i = 0; i < N; i++) {
        for(let j = 0; j < N; j++) {
            console.log(graph[i][j] ? 1 : 0);
        }
    }
}

transitiveClosureGraph(["5 5", "0 1", "0 2", "1 2", "2 3", "3 4"]);

This JavaScript code uses an adjacency matrix representation of the graph. The graph is constructed by iterating through the edges of the input and setting the appropriate indices in the matrix. For every vertex k, it then checks all possible vertices i and j and updates the matrix if it can reach vertex j from vertex k.

The time complexity of this solution is O(N^3), which is quite efficient.