Sure, here is a simple JavaScript code snippet for your problem. This code assumes that the Binary Search Tree is represented as an array where the parent node is at index i and the left child at 2*i + 1 and the right child at 2*i + 2.

function findKey(arr, rank) {
    if (rank >= arr.length) {
        console.log('Invalid rank');
        return;
    }
    return arr[rank];
}

// Example usage
let arr = [1, 2, 3, 4, 5, 6, 7]; // Binary Search Tree
let rank = 3; // The rank of the key to find
let key = findKey(arr, rank);
console.log('The key at rank', rank, 'is', key);

This code first checks if the given rank is valid. If it is not, it prints an error message and returns. If the rank is valid, it finds and prints the key at the given rank.

Please note that this code assumes that you have already defined the Binary Search Tree and the rank for which you want to find the key. You should provide these in the appropriate place for your use case.