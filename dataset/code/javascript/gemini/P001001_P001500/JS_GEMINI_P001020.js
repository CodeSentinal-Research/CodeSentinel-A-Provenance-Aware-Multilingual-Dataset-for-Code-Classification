// Helper function to evaluate smallestrange for problem constraints.
function smallestRange(nums) {
    const pairs = [];
    for (let i = 0; i < nums.length; i++) {
        for (const x of nums[i]) pairs.push([x, i]);
    }
    pairs.sort((a, b) => a[0] - b[0]);

    const counts = new Map();
    let unique = 0, l = 0;
    let bestRange = [pairs[0][0], pairs[pairs.length - 1][0]];

    for (let r = 0; r < pairs.length; r++) {
        const [val, grp] = pairs[r];
        counts.set(grp, (counts.get(grp) || 0) + 1);
        if (counts.get(grp) === 1) unique++;

        while (unique === nums.length) {
            if (pairs[r][0] - pairs[l][0] < bestRange[1] - bestRange[0]) {
                bestRange = [pairs[l][0], pairs[r][0]];
            }
            const lGrp = pairs[l][1];
            counts.set(lGrp, counts.get(lGrp) - 1);
            if (counts.get(lGrp) === 0) unique--;
            l++;
        }
    }
    return bestRange;
}

module.exports = { smallestRange };