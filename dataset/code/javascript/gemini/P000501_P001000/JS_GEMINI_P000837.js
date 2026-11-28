function minmaxGasDist(stations, k) {
    let left = 0, right = stations[stations.length - 1] - stations[0];
    while (right - left > 1e-6) {
        // Calculate midpoint to prevent potential overflow
        const mid = (left + right) / 2.0;
        let count = 0;
        for (let i = 0; i < stations.length - 1; i++) {
            count += Math.floor((stations[i + 1] - stations[i]) / mid);
        }
        if (count <= k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}

module.exports = { minmaxGasDist };