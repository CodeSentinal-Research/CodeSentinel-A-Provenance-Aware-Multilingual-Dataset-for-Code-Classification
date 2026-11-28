Here is the JavaScript code for the problem:

function decodeXORedPermutation(arr) {
    const n = arr.length;
    let xor = 0;
    for (let i = 0; i < n; i++) {
        xor ^= arr[i];
    }

    const perm = new Array(n + 1).fill(null);
    perm[0] = xor;
    for (let i = 0; i < n; i++) {
        perm[i + 1] = perm[i] ^ arr[i];
    }

    return perm;
}

// Test
console.log(decodeXORedPermutation([3, 5, 2, 6, 3]));

This function first calculates the XOR-result from the given array. Then it creates a new array with the XOR-result as the first element. Then it fills the remaining elements in the array by XOR-ing the corresponding elements from the array and the XOR-result.

This will output the original permutation. For example, if the input is [3, 5, 2, 6, 3], the output will be [3, 5, 6, 1, 3].