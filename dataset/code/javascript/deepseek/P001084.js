Here is the JavaScript code for the problem:

function hamiltonianCycle() {
    let [n, m] = readLine().split(' ').map(Number);
    let graph = new Array(n).fill(null).map((_, i) => ({
        from: [],
        to: [],
    }));

    for (let i = 0; i < m; i++) {
        let [u, v] = readLine().split(' ').map(Number);
        graph[u].from.push(v);
        graph[v].to.push(u);
    }

    let visited = new Array(n + 1).fill(false);
    let recStack = new Array(n + 1).fill(false);

    function dfs(node) {
        visited[node] = true;
        for (let neighbor of graph[node].from) {
            if (!visited[neighbor] && dfs(neighbor)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }

    for (let node = 1; node <= n; node++) {
        if (dfs(node)) {
            console.log('YES');
            return;
        }
    }

    console.log('NO');
}

hamiltonianCycle();

This program reads the number of nodes and edges from the input, and then builds the graph. It then checks each node to see if there's a Hamiltonian cycle.

Please note that you need to provide a `readLine()` function, which is a mock function for reading line from the console. The actual implementation may vary depending on the environment you're using (e.g., Node.js, Browser, etc.).