Here is the JavaScript code to solve the problem.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = +rl.readline();

rl.on('line', function(line) {
    let arr = line.split(' ').map(Number);
    console.log(findLongestBitonicSubsequence(arr));
});

function findLongestBitonicSubsequence(arr) {
    let n = arr.length;
    if(n == 0) return 0;
    
    let lis = Array(n).fill(1);
    let lds = Array(n).fill(1);
    
    for(let i=0; i<n; i++) {
        for(let j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                lis[i] = Math.max(lis[i], lis[j] + 1);
            }
        }
    }
    
    for(let i=n-1; i>=0; i--) {
        for(let j=n-1; j>i; j--) {
            if(arr[i] > arr[j]) {
                lds[i] = Math.max(lds[i], lds[j] + 1);
            }
        }
    }
    
    let maxLength = 1;
    for(let i=0; i<n; i++) {
        maxLength = Math.max(maxLength, lis[i] + lds[i] - 1);
    }
    
    return maxLength;
}

The code reads the number of test cases and then reads the test cases line by line. For each test case, it reads the input numbers and outputs the length of the longest bitonic subsequence.

The `findLongestBitonicSubsequence` function calculates the longest increasing subsequence (lis) and longest decreasing subsequence (lds) for each element in the array. The length of the longest bitonic subsequence is calculated as the sum of lengths of longest increasing subsequence and longest decreasing subsequence minus 1 for each element.