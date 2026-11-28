function solve() {
    var n = parseInt(readLine());
    var tree = new Array(n+1);
    for(var i = 1; i <= n; i++){
        tree[i] = readLine().split(' ');
    }
    var count = 0;
    for(var i = 1; i <= n; i++){
        if(tree[i][0] !== 'N' && tree[i][1] !== 'N' && tree[i][2] !== 'N'){
            count++;
        }
    }
    console.log(count);
}
This JavaScript code reads input from the console and processes it in a binary tree way. It first reads the number of nodes and then reads the node information line by line. For each line, it splits it and checks if the third element is 'N'. If it's not, it increments a counter. After all nodes have been processed, it prints the count. 

Note: This code assumes the tree nodes are stored in an array where the index corresponds to the node and the value at index 0 is the parent of the node, at index 1 is the left child of the node, and at index 2 is the right child of the node. If the tree is represented differently, the code will need to be adjusted accordingly.