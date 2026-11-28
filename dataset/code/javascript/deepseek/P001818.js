Here is a JavaScript solution using recursive approach to find the lowest common ancestor of multiple nodes in a binary search tree:

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function insert(root, data) {
    if(root === null) {
        root = new Node(data);
        return root;
    }
    if(data < root.data) {
        root.left = insert(root.left, data);
    } else {
        root.right = insert(root.right, data);
    }
    return root;
}

function findLCA(root, node1, node2) {
    if(root === null) {
        return null;
    }
    if(root.data > node1 && root.data > node2) {
        return findLCA(root.left, node1, node2);
    }
    if(root.data < node1 && root.data < node2) {
        return findLCA(root.right, node1, node2);
    }
    return root;
}

function main() {
    let N = 7;
    let keys = [20, 8, 22, 4, 12, 10, 14];
    let root = null;
    for(let i = 0; i < N; i++) {
        root = insert(root, keys[i]);
    }
    let node1 = 4;
    let node2 = 12;
    let lca = findLCA(root, node1, node2);
    console.log('LCA of '+ node1 +' and '+ node2 +' is '+ lca.data);
}

main();

This program first creates a binary search tree from the given keys. Then, it finds the lowest common ancestor of two nodes. The `insert` function is used to add nodes to the binary search tree and the `findLCA` function is used to find the LCA of two given nodes.

The `main` function creates a binary search tree from the given keys, then finds the lowest common ancestor of two nodes, and prints the result.