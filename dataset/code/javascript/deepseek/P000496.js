function sumSubarrayMins(n, arr) {
    const MOD = 1e9 + 7;
    let sum = 0;
    let minArr = Array(n).fill(Infinity);

    sum += arr[0];
    minArr[0] = arr[0];
    for(let i = 1; i < n; i++){
        arr[i] < minArr[i-1] ? sum += arr[i] : sum += minArr[i-1];
        minArr[i] = Math.min(arr[i], minArr[i-1]);
    }
    return sum % MOD;
}