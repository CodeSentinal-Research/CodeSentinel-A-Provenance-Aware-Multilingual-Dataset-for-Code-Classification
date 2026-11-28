function rotateLeft(arr, k) {
    if (!arr || arr.length === 0) return [];
    k = k % arr.length;
    return arr.slice(k).concat(arr.slice(0, k));
}

module.exports = { rotateLeft };