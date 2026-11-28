process.stdin.resume();
process.stdin.on('data', (chunk) => {
    var N = chunk.toString().trim();
    N = parseInt(N);
    var nodes = [];
    process.stdin.on('data', (chunk) => {
        var line = chunk.toString().trim();
        if (line.length == 0) {
            var tree = buildTree(nodes);
            console.log(everyLeafHasSibling(tree) ? "YES" : "NO");
            process.stdin.pause();
        } else {
            nodes.push(line);
        }
    });
});

function buildTree(nodes) {
    var childrenCount = {};
    var children = {};
    nodes.forEach(node => {
        var parts = node.split(' ');
        var parent = parts[0];
        var child = parts[1];
        childrenCount[parent] = childrenCount[parent] ? childrenCount[parent] + 1 : 1;
        children[child] = child;
    });

    var root = Object.keys(childrenCount).find(key => childrenCount[key] === childrenCount[key]);

    function dfs(node, parent) {
        if (children[node]) {
            var left = children[node];
            var right = children[left];
            if (!right) {
                if (parent !== root) {
                    return false;
                }
            } else {
                if (!dfs(left, node) || !dfs(right, node)) {
                    return false;
                }
            }
        }
        return true;
    }

    return dfs(root, null);
}

function everyLeafHasSibling(tree) {
    return tree;
}

This JavaScript solution uses the concept of depth-first search (DFS) to traverse the tree and check if every leaf has a sibling. It reads the number of nodes and their connections from standard input. The tree is built by counting the children of each node and finding the root node. DFS is used to check if every leaf has a sibling.