Here is the JavaScript code for the given problem:


function solve(root, target) {
    let time = new Map();
    let minTime = new Map();
    let maxTime = new Map();
    let result = Infinity;

    function dfs(node, parent = null) {
        if (!node) {
            return;
        }

        if (node.value === target) {
            time.set(node, 0);
            minTime.set(node, 0);
            maxTime.set(node, 0);
            result = 0;
        }

        time.set(node, time.get(parent) + 1);

        if (time.get(node) > minTime.get(node)) {
            minTime.set(node, time.get(node));
            result = Math.min(result, minTime.get(node));
        }

        if (time.get(node) > maxTime.get(node)) {
            maxTime.set(node, time.get(node));
       
            if(maxTime.get(node) - minTime.get(node) > result) {
                result = maxTime.get(node) - minTime.get(node);
            }
        }

        dfs(node.left, node);
        dfs(node.right, node);
    }

    dfs(root);

    return result;
}

class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}


In this code, we use depth-first search (DFS) to traverse the tree and find the minimum and maximum times to burn the tree. We use three maps: `time`, `minTime`, and `maxTime`. The `time` map stores the time it took to reach the current node, the `minTime` map stores the minimum time it took to reach the current node, and the `maxTime` map stores the maximum time it took to reach the current node. The `result` variable is used to store the minimum time required to burn the entire tree.