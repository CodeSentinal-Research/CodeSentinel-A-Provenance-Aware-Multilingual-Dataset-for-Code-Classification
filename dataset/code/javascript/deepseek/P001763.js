Here is the JavaScript solution for the problem:

// Binary Tree Node
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

// Recursive function to count the number of univalue subtrees
let count = 0;
function solve(root) {
    if(root == null) return true;
    let left = solve(root.left);
    if(left == false) return false;
    let right = solve(root.right);
    if(right == false) return false;
    if(root.left != null && root.val != root.left.val) return false;
    if(root.right != null && root.val != root.right.val) return false;
    count++;
    return true;
}

process.stdin.resume();
process.stdin.on('data', function(data){
    let N = parseInt(data);
    let arr = [];
    for(let i = 0; i < N * N; i++) {
        arr.push(parseInt(process.stdin.read()));
    }
    let root = new TreeNode(arr[0]);
    let index = 1;
    while(index < N * N) {
        if(arr[index] == -1) {
            root.left = null;
        } else {
            root.left = new TreeNode(arr[index]);
        }
        index++;
        if(index < N * N) {
            if(arr[index] == -1) {
                root.right = null;
            } else {
                root.right = new TreeNode(arr[index]);
            }
        }
        solve(root);
        console.log(count);
        count = 0;
        root = new TreeNode(arr[0]);
    }
});
In this solution, we use a recursive function `solve` to count the number of univalue subtrees. The function `solve` takes as input a tree node and returns `true` if the tree rooted at that node is a univalue subtree, and `false` otherwise. If the tree rooted at the current node is not univalue (i.e., if it contains values different from the root's), the function returns `false`.

In the main part of the script, we read the input and create a binary tree. We call the `solve` function for each node in the tree and print the number of univalue subtrees at each step.