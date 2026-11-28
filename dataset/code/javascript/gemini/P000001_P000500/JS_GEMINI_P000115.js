function rotateRight(arr, k) {
    if (!arr || arr.length === 0) return [];
    k = k % arr.length;
    if (k === 0) return arr.slice();
    return arr.slice(-k).concat(arr.slice(0, -k));
}

module.exports = { rotateRight };