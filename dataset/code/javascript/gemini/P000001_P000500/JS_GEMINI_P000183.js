function countDistinct(arr, k) {
    const res = [];
    const freq = new Map();
    let distinct = 0;

    for (let i = 0; i < k; i++) {
        freq.set(arr[i], (freq.get(arr[i]) || 0) + 1);
        if (freq.get(arr[i]) === 1) distinct++;
    }
    res.push(distinct);

    for (let i = k; i < arr.length; i++) {
        const out = arr[i - k];
        freq.set(out, freq.get(out) - 1);
        if (freq.get(out) === 0) distinct--;

        const inVal = arr[i];
        freq.set(inVal, (freq.get(inVal) || 0) + 1);
        if (freq.get(inVal) === 1) distinct++;

        res.push(distinct);
    }
    return res;
}

module.exports = { countDistinct };