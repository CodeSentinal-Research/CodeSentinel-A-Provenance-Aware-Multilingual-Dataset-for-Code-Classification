In JavaScript, you can use the Depth-First Search (DFS) approach to solve this problem. First, initialize a map to store the nodes along with their vertical position and column. Then, recursively call the DFS function for each node. 

Here is the code:

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var verticalOrder = function(root) {
    const map = new Map();
    let min = 0, max = 0;
    
    const DFS = (node, row, col) => {
        if (!node) return;
        DFS(node.left, row - 1, col + 1);
        if (!map.has(col)) map.set(col, []);
        map.get(col).push({node, row});
        min = Math.min(min, col);
        max = Math.max(max, col);
        DFS(node.right, row + 1, col + 1);
    };
    
    DFS(root, 0, 0);
    const res = [];
    for (let i = min; i <= max; i++) {
        res.push(map.get(i).map(x => x.node));
    }
    return res;
};
In the code above, the `DFS` function traverses the tree in a depth-first manner. Each time a node is visited, it is added to the map, with the column index as the key and the node and its row as the value. The minimum and maximum column indices are updated as needed. The final result is obtained by iterating over the keys in the map and pushing the node values associated with each key. The final result is a list of lists, where each inner list contains the nodes at the same vertical position.