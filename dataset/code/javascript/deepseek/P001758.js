Here is the JavaScript code to solve the problem:

function findDuplicates(inputs) {
    let N = inputs[0];
    inputs.shift();
    let tree = new Set();

    for(let i = 0; i < N; i++) {
        let node = inputs[i];
        if(tree.has(node)) {
            console.log('YES');
            return;
        }
        tree.add(node);
    }

    console.log('NO');
}

This function takes an array of inputs. It first gets the first element from the array (which is the number of nodes in the tree), and then it creates a Set to store the values of the tree. It then loops through the rest of the array, and for each node, it checks if the node is already in the set. If it is, it means the node is a duplicate, and it outputs 'YES'. If it is not in the set, it adds the node to the set. If it has gone through all the nodes and found no duplicates, it outputs 'NO'.

To use this function, you would call it with an array of inputs, where each element represents a line of input. For example:

findDuplicates([5, 1, 2, 3, 4, 2]);

This would output 'YES' because the number 2 appears twice in the tree.