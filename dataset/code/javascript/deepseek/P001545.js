function minDifference(arr, k) {
    arr.sort((a, b) => a - b);
    let minDiff = Infinity;
    for (let i = 0; i <= arr.length - k; i++) {
        minDiff = Math.min(minDiff, arr[i + k - 1] - arr[i]);
    }
    return minDiff;
}

let [n, k] = readline().split(" ").map(Number);
let arr = readline().split(" ").map(Number);
console.log(minDifference(arr, k));