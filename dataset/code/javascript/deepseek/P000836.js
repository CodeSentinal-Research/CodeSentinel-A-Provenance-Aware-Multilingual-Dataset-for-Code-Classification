function maxDistance(n, positions, m) {
    positions.sort((a, b) => a - b);
    let low = 0;
    let high = positions[n - 1] - positions[0];

    while (low < high) {
        let mid = Math.floor((low + high) / 2);

        if (canPlace(positions, m, mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return high - 1;
}

function canPlace(positions, m, distance) {
    let last = positions[0];
    let count = 1;

    for (let i = 1; i < positions.length; i++) {
        if (positions[i] - last >= distance) {
            last = positions[i];
            count++;

            if (count == m) {
                return true;
            }
        }
    }

    return false;
}

The `maxDistance` function first sorts the positions array. Then, it uses binary search to find the maximum minimum distance. In the `canPlace` function, it checks if we can place m balls with a given distance. If we can, it means the distance is too small so we increase the distance, otherwise we decrease the distance. The time complexity is O(n log m), which is acceptable for this problem.