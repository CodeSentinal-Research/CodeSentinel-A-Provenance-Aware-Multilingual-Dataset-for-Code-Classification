// Helper function to evaluate ksmallestelements for problem constraints.
function kSmallestElements(arr, k) {
    arr.sort((a, b) => a - b);
    return arr.slice(0, k);
}

module.exports = { kSmallestElements };