Here is a JavaScript solution that uses a recursive approach to check if two insertion sequences generate the same BST:

// Definition for a binary tree node.
function TreeNode(val) {
    this.val = val;
    this.left = null;
    this.right = null;
}

function isSameBST(sequence1, sequence2) {
    if (sequence1.length !== sequence2.length) {
        return false;
    }

    let root1 = new TreeNode(sequence1[0]);
    let root2 = new TreeNode(sequence2[0]);

    for (let i = 1; i < sequence1.length; i++) {
        insertIntoBST(root1, sequence1[i]);
    }

    for (let i = 1; i < sequence2.length; i++) {
        if (!isSameTree(root1, root2, sequence2[i])) {
            return false;
        }
    }

    return true;
}

function insertIntoBST(root, val) {
    if (root === null) {
        root = new TreeNode(val);
        return;
    }

    if (val < root.val) {
        if (root.left === null) {
            root.left = new TreeNode(val);
        } else {
            insertIntoBST(root.left, val);
        }
    } else {
        if (root.right === null) {
            root.right = new TreeNode(val);
        } else {
            insertIntoBST(root.right, val);
        }
    }
}

function isSameTree(p, q, x) {
    if (p === null && q === null) {
        return true;
    }

    if (p === null || q === null) {
        return false;
    }

    if (p.val !== q.val) {
        return false;
    }

    return isSameTree(p.left, q.left, x) && isSameTree(p.right, q.right, x);
}

Please note that this code assumes the input sequences are provided as two arrays of integers, where the first array represents the first insertion sequence and the second array represents the second insertion sequence.

Also, this code only works for the problem statement, as it does not account for the case where a tree can be generated from either sequence, and there are multiple valid trees that could be generated from the same sequence. If you want to specifically check if a tree is generated from a sequence, you would need to implement additional logic.