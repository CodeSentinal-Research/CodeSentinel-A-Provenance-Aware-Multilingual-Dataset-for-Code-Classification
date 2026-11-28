function findPlatform(arr, dep, n) {
    arr.sort((a, b) => a - b);
    dep.sort((a, b) => a - b);

    let platforms = 0, maxPlatforms = 0;
    let i = 0, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            if (platforms > maxPlatforms) maxPlatforms = platforms;
            i++;
        } else {
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}

module.exports = { findPlatform };