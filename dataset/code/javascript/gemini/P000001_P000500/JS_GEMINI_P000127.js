function maxArea(height) {
    let l = 0, r = height.length - 1;
    let maxWater = 0;
    while (l < r) {
        const h = Math.min(height[l], height[r]);
        maxWater = Math.max(maxWater, h * (r - l));
        if (height[l] < height[r]) l++;
        else r--;
    }
    return maxWater;
}

module.exports = { maxArea };