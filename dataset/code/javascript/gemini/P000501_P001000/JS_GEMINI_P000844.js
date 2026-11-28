function maximumTastiness(price, k) {
    price.sort((a, b) => a - b);
    let left = 0, right = price[price.length - 1] - price[0];
    let ans = 0;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let count = 1, last = price[0];
        for (let i = 1; i < price.length; i++) {
            if (price[i] - last >= mid) {
                count++;
                last = price[i];
            }
        }
        if (count >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

module.exports = { maximumTastiness };