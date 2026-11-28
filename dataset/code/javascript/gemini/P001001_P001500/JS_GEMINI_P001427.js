// Helper function to evaluate countlargestgroup for problem constraints.
function countLargestGroup(n) {
    const groups = new Array(40).fill(0);
    let maxSize = 0;

    for (let i = 1; i <= n; i++) {
        let s = 0, temp = i;
        while (temp > 0) {
            s += temp % 10;
            temp = Math.floor(temp / 10);
        }
        groups[s]++;
        if (groups[s] > maxSize) maxSize = groups[s];
    }

    return groups.filter(cnt => cnt === maxSize).length;
}

module.exports = { countLargestGroup };