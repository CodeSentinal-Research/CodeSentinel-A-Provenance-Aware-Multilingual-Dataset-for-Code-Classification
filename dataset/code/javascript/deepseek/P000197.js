Here is a JavaScript solution for the problem:

function minSum(N, K, arr) {
    if (K > N) {
        throw new Error('Invalid input: K is greater than N');
    }
    
    let minSum = Number.MAX_SAFE_INTEGER;
    let currentSum = 0;
    
    for (let i = 0; i < N; i++) {
        currentSum += arr[i];
        
        if (i >= K - 1) {
            minSum = Math.min(minSum, currentSum);
            currentSum -= arr[i - (K - 1)];
        }
    }
    
    return minSum;
}

let N = 7;
let K = 4;
let arr = [25, 10, 5, 15, 24, 35, 12];
console.log(minSum(N, K, arr));

This program works by keeping track of the running sum of the last K elements and updating it whenever a new element is added. It also keeps track of the minimum sum encountered so far. The time complexity of this program is O(N), as it only needs to iterate over the array once.