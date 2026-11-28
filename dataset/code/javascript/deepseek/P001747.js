Here is the JavaScript code for the given problem:

let tree = {
    data: null,
    left: null,
    right: null,
    level: 1,
    leaves: 0
};

let maxLeafLevel = -Infinity;
let maxLeafCount = -Infinity;
let maxLeafCountLevel = -Infinity;
let currentLevel = 1;
let leafCount = 0;

function readInput() {
    let n = parseInt(readline());
    for (let i = 0; i < n; i++) {
        let [node, left, right] = readline().split(' ');
        tree[node] = { data: node, left: left === null ? null : left, right: right === null ? null : right, level: currentLevel, leaves: 0 };
        if (i < n - 1) {
            tree[node].left = left === null ? null : left;
            tree[node].right = right === null ? null : right;
        }
    }
}

function traverseTree(node, level) {
    if (node === null) {
        return;
    }
    if (node.left === null && node.right === null) {
        leafCount++;
    }
    if (leafCount > maxLeafCount) {
        maxLeafCount = leafCount;
        maxLeafLevel = level;
    }
    if (leafCount === maxLeafCount) {
        maxLeafCountLevel = Math.min(maxLeafCountLevel, level);
    }
    traverseTree(node.left, level + 1);
    traverseTree(node.right, level + 1);
}

readInput();
traverseTree(tree, 1);
console.log(maxLeafCountLevel);

This code reads the input and builds the tree. Then it traverses the tree, counting the leaf nodes at each level. If it finds a level with more leaf nodes than the current maxLeafLevel, it updates the maxLeafLevel and maxLeafCount. If it finds a level with the same number of leaf nodes as the current maxLeafCount, it updates the maxLeafCountLevel to be the smallest level number among the levels with the same maximum leaf count. Finally, it outputs the smallest level number with the maximum number of leaf nodes.