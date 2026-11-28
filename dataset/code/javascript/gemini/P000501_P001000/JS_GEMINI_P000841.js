function maximumCandies(candies, k) {
    let left = 1, right = Math.max(...candies);
    let ans = 0;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let children = 0;
        for (const c of candies) {
            children += Math.floor(c / mid);
        }
        if (children >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

module.exports = { maximumCandies };