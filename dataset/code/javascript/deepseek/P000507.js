function isValidSerialization(preorder) {
    var nodes = preorder.split(',');
    var diff = 1;
    for (var i = 0; i < nodes.length; i++) {
        diff--;
        if (diff < 0) {
            return false;
        }
        if (nodes[i] !== '#') {
            diff += 2;
        }
    }
    return diff === 0;
}

console.log(isValidSerialization('9,3,4,#,#,1,#,#,2,#,6,#'));  // true
console.log(isValidSerialization('1,#,2,3,4,#,5,#,#,#'));  // false

The function `isValidSerialization` takes a string as a parameter, which represents the preorder serialization of a binary tree. 

The function first splits the input string into an array of nodes using the `split` method. Then, it initializes a variable `diff` to 1.

The function then iterates over each node in the array. For each node, it decrements `diff` by 1. If `diff` becomes less than 0, it means we've reached the root of the tree, and the serialization is not valid. The function then checks if the node is not `#`. If it is not, it increments `diff` by 2.

Finally, the function returns whether `diff` is 0. If `diff` is 0, it means we've visited all nodes of the tree, and the serialization is valid.