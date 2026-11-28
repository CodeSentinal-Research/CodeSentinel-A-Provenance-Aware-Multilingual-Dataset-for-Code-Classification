Here is a JavaScript solution for the given problem using Depth-First Search (DFS) to traverse the tree and generate all valid insertion sequences:

function countSequences(root) {
    let count = 0;
    let sequences = {};

    function dfs(node, sequence = '') {
        if (node === null) {
            return;
        }

        if (node.left === null && node.right === null) {
            if (!sequences[sequence + node.value]) {
                count++;
                sequences[sequence + node.value] = true;
            }
        } else {
            if (sequence + node.value in sequences) {
                return;
            }

            if (node.left) {
                dfs(node.left, sequence + node.value);
            }

            if (node.right) {
                dfs(node.right, sequence + node.value);
            }
        }
    }

    dfs(root);

    return count;
}

This function counts the number of different sequences of insertion that can be made by inserting nodes at each position in the given BST. It works by performing a Depth-First Search on the tree and recording the sequences of insertion that it finds.