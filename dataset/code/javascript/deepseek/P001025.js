Sure, here's a simple JavaScript code that calculates the number of internal nodes in a complete binary heap. 

function countInternalNodes(N) {
    if (N < 1 || N > 10^9) {
        console.log('Invalid input!');
        return;
    }
    // Number of internal nodes = Number of leaves + root
    // Therefore, we can use the formula: (N/2) + 1 = N in this case
    console.log(Math.floor(N/2) + 1);
}

You can call this function with the number of nodes in the heap as an argument. For example, if you have 8 nodes in the heap, you can call `countInternalNodes(8);` to get the result.