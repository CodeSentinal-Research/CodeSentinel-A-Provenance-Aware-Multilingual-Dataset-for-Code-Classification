Here's a JavaScript solution for your problem. It uses a basic XOR operation to find the XOR of a range of elements in an array. The solution is efficient and handles the constraints and requirements of the problem.

let N, arr, Q, l, r;
N = parseInt(readline());
arr = readline().split(' ').map(Number);
Q = parseInt(readline());
for(let i = 0; i < Q; i++) {
    [l, r] = readline().split(' ').map(Number);
    console.log(findXOR(l, r));
}

function findXOR(l, r) {
    let res = 0;
    for(let i = l; i <= r; i++) {
        res ^= arr[i];
    }
    return res;
}

This solution reads the inputs in a simple manner. It first reads the number of elements (N) and the array of elements. Then it reads the number of queries (Q). For each query, it reads the start and end indices (l, r) and prints the XOR of the range.

Please note that this code assumes you are using Node.js with a `readline` function to read inputs. If you are not using Node.js or you are using a different environment, the code will need to be adjusted accordingly.