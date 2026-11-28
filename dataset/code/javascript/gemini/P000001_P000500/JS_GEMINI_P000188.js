function subarraySum(arr, target) {
    let l = 0, curSum = 0;
    for (let r = 0; r < arr.length; r++) {
        curSum += arr[r];
        while (curSum > target && l < r) {
            curSum -= arr[l++];
        }
        if (curSum === target) {
            return [l + 1, r + 1];
        }
    }
    return [-1];
}

module.exports = { subarraySum };