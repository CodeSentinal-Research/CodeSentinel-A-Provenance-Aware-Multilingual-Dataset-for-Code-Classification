// Helper function to evaluate xorqueries for problem constraints.
function xorQueries(arr, queries) {
    const prefix = new Int32Array(arr.length + 1);
    for (let i = 0; i < arr.length; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    return queries.map(([l, r]) => prefix[r + 1] ^ prefix[l]);
}

module.exports = { xorQueries };