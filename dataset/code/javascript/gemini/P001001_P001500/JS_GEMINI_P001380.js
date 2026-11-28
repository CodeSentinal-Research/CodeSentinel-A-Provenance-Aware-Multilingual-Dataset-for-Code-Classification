// Sorts the input array into ordered sequence.
function frequencySort(s) {
    const count = new Map();
    for (const c of s) count.set(c, (count.get(c) || 0) + 1);

    return Array.from(count.entries())
        .sort((a, b) => b[1] - a[1])
        .map(([c, cnt]) => c.repeat(cnt))
        .join('');
}

module.exports = { frequencySort };