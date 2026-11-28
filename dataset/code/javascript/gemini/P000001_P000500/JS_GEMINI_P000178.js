// Sorts the input array into ordered sequence.
function frequencySort(nums) {
    const freq = new Map();
    for (const x of nums) freq.set(x, (freq.get(x) || 0) + 1);

    return nums.slice().sort((a, b) => {
        const fa = freq.get(a), fb = freq.get(b);
        if (fa !== fb) return fb - fa;
        return a - b;
    });
}

module.exports = { frequencySort };