Here is the JavaScript code for the problem.

// Reading and parsing inputs
let N = parseInt(readline());
let arr = readline().split(' ').map(Number);
let Q = parseInt(readline());

let rangeQueries = [];
for(let i = 0; i < Q; i++) {
    rangeQueries[i] = readline().split(' ').map(Number);
}

// Function to count positive numbers in a range
function countPositives(arr, queries) {
    let count = new Array(arr.length).fill(0);

    for(let i = 0; i < arr.length; i++) {
        if(arr[i] > 0) {
            count[i] = 1;
        }
    }

    for(let query of queries) {
        let start = query[0] - 1;
        let end = query[1];

        if(start >= 0 && end < arr.length) {
            console.log(count[end] - (start > 0 ? count[start - 1] : 0));
        }
    }
}

countPositives(arr, rangeQueries);

This script will read the size of the array and array elements, and then read the count of range queries. Then it will count positive numbers in the array and for each query, it will print the count in the range.