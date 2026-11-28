function slidingWindowSum(arr, k) {
    const result = [];
    let sum = 0;
    for (let i = 0; i < k; i++) sum += arr[i];
    result.push(sum);
    for (let i = k; i < arr.length; i++) {
        sum += arr[i] - arr[i - k];
        result.push(sum);
    }
    return result;
}

module.exports = { slidingWindowSum };
