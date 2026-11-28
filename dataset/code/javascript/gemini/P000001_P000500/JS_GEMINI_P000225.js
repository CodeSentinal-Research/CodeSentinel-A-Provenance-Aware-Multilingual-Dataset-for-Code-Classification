function minSwaps(nums) {
    const n = nums.length;
    const arrPos = nums.map((val, idx) => [idx, val]);
    arrPos.sort((a, b) => a[1] - b[1]);

    const visited = new Array(n).fill(false);
    let swaps = 0;

    for (let i = 0; i < n; i++) {
        if (visited[i] || arrPos[i][0] === i) continue;

        let cycleSize = 0;
        let j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arrPos[j][0];
            cycleSize++;
        }

        if (cycleSize > 0) swaps += cycleSize - 1;
    }
    return swaps;
}

module.exports = { minSwaps };