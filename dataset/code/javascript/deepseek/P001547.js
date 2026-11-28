Here is a simple implementation of the problem in JavaScript:

function maxOddElements(N, K, arr) {
    let max = 0;
    let oddCount = 0;
    for (let i = 0; i < K; i++) {
        if (arr[i] % 2 !== 0) {
            oddCount++;
        }
    }
    max = oddCount;
    for (let i = K; i < N; i++) {
        if (arr[i] % 2 !== 0) {
            oddCount++;
        }
        if (arr[i - K] % 2 === 0) {
            oddCount--;
        }
        max = Math.max(max, oddCount);
    }
    return max;
}

In the code above, we first initialize `max` to 0 and `oddCount` to 0. We then loop through the array for the first `K` elements and count the number of odd numbers. After that, we initialize `max` to `oddCount` and loop through the rest of the array. For each element, we update `oddCount` by 1 if the current element is odd, and -1 if the previous element is even. We also update `max` when `oddCount` changes. At the end, `max` will be the maximum number of odd integers in a window of size `K`.