let N = parseInt(readline());
let X = parseInt(readline());
let arr = readline().split(' ').map(Number);

let minLen = Infinity;
let sum = 0;
let left = 0;

for (let right = 0; right < N; right++) {
    sum += arr[right];

    while (sum > X) {
        sum -= arr[left];
        left++;
    }

    if (sum > X && right - left + 1 < minLen) {
        minLen = right - left + 1;
    }
}

if (minLen === Infinity) {
    console.log(-1);
} else {
    console.log(minLen);
}
This code reads the input and uses two pointers to find the minimum length subarray with a sum greater than X. It maintains a sliding window of elements and moves the window towards the right until the sum is greater than X. If the sum at any point exceeds X, it moves the left pointer to the right. If the current subarray sum is greater than X and its length is less than the minimum length found so far, it updates the minimum length. If no such subarray is found, it prints -1.