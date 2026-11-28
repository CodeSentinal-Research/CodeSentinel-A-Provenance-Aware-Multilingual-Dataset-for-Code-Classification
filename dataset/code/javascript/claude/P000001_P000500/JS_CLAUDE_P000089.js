function mySqrt(x) {
    if (x < 2) return x;
    let l = 1, r = Math.floor(x / 2), ans = 1;
    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        if (mid * mid === x) return mid;
        else if (mid * mid < x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

module.exports = { mySqrt };
