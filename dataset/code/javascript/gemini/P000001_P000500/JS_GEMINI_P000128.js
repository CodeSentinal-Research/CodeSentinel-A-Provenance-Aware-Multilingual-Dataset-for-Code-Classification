function trap(height) {
    if (!height.length) return 0;
    let l = 0, r = height.length - 1;
    let lMax = height[l], rMax = height[r];
    let water = 0;

    while (l < r) {
        if (lMax < rMax) {
            l++;
            lMax = Math.max(lMax, height[l]);
            water += lMax - height[l];
        } else {
            r--;
            rMax = Math.max(rMax, height[r]);
            water += rMax - height[r];
        }
    }
    return water;
}

module.exports = { trap };