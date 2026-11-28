function equilibriumIndex(arr) {
    let totalSum = arr.reduce((prev, curr) => prev + curr, 0);
    let leftSum = 0;

    for(let i = 0; i < arr.length; i++) {
        totalSum -= arr[i];
        if(leftSum === totalSum) {
            return i;
        }
        leftSum += arr[i];
    }
    return -1;
}

// Test the function with input
console.log(equilibriumIndex([-7, 1, 5, 2, -4, 3, 0])); // Output: 3
console.log(equilibriumIndex([1, 2, 3, 4, 5, 6])); // Output: -1