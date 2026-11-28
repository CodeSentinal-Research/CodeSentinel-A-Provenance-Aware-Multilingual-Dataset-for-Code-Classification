// Helper function to evaluate minplatforms for problem constraints.
function minPlatforms(arr, dep) {
    arr.sort((a, b) => a - b);
    dep.sort((a, b) => a - b);
    const n = arr.length;
    let i = 0, j = 0;
    let platNeeded = 0, maxPlat = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platNeeded++;
            maxPlat = Math.max(maxPlat, platNeeded);
            i++;
        } else {
            platNeeded--;
            j++;
        }
    }
    return maxPlat;
}

module.exports = { minPlatforms };