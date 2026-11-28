function rangeSum(nums, n, q, queries) {
    const prefixSum = [];
    prefixSum[0] = nums[0];
    for (let i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    for (let i = 0; i < q; i++) {
        const [left, right] = queries[i];
        if (left > 0) {
            console.log(prefixSum[right] - prefixSum[left - 1]);
        } else {
            console.log(prefixSum[right]);
        }
    }
}
This function takes an array of integers `nums`, the length of `nums`, the number of queries `q`, and an array of queries `queries` where each query is a pair of integers. It first computes the prefix sum array `prefixSum`, where `prefixSum[i]` is the sum of all elements in `nums[0..i]`. Then for each query, it prints the sum of the elements between indices `left` and `right` (inclusive) in the array. If `left` is greater than 0, it subtracts the sum of the elements in `nums[0..left - 1]` from the sum in `nums[left..right]`. If `left` is 0, it just prints the sum of the entire array.