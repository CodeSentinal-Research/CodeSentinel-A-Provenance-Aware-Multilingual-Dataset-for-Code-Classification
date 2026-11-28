function leaders(arr) {
    const res = [];
    let maxFromRight = -Infinity;
    for (let i = arr.length - 1; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            res.push(arr[i]);
            maxFromRight = arr[i];
        }
    }
    return res.reverse();
}

module.exports = { leaders };