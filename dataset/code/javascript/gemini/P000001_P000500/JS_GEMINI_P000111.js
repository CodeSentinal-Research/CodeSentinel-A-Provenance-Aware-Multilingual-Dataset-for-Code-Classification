function findSecondLargest(arr) {
    if (!arr || arr.length < 2) return null;
    const unique = Array.from(new Set(arr)).sort((a, b) => a - b);
    if (unique.length < 2) return null;
    return unique[unique.length - 2];
}

module.exports = { findSecondLargest };