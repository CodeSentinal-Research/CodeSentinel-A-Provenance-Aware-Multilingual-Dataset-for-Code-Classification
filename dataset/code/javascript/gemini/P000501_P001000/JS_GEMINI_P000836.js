function maxDistance(position, m) {
    position.sort((a, b) => a - b);
    let left = 1, right = position[position.length - 1] - position[0];
    let ans = 1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let count = 1, last = position[0];
        for (let i = 1; i < position.length; i++) {
            if (position[i] - last >= mid) {
                count++;
                last = position[i];
            }
        }
        if (count >= m) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

module.exports = { maxDistance };