let N = parseInt(readline());
let arr = readline().split(' ').map(Number);

let maxSum = arr[0];
let currSum = arr[0];

for(let i = 1; i < N; i++){
    currSum = Math.max(arr[i], currSum + arr[i]);
    maxSum = Math.max(maxSum, currSum);
}

print(maxSum);