function solve() {
    const [N, ...nodes] = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n').map(Number);
    const tree = {};
    let max = 0;

    for (let i = 0; i < N; i++) {
        const [node, left, right] = nodes[i].split(' ').map(Number);
        tree[node] = [left, right];
    }

    function dfs(node) {
        if (!tree[node]) {
            return 0;
        }

        const rob = dfs(tree[node][0]) + dfs(tree[node][1]) + 1;
        const not_rob = Math.max(dfs(tree[node][0]), dfs(tree[node][1])) + 1;

        max = Math.max(max, rob);
        return not_rob;
    }

    dfs(1);

    console.log(max);
}

solve();
This JavaScript solution reads the input and creates a tree from it. It then uses a depth-first search (DFS) to find the maximum amount that can be robbed if robbed houses are connected. The `max` variable is updated in each iteration of the DFS to store the maximum amount that can be robbed. The `dfs` function recursively calculates the maximum amount robbed if the current node is robbed and if it is not robbed.