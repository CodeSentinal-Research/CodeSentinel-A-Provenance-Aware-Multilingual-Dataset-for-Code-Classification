// Helper function to evaluate sumheapelements for problem constraints.
function sumHeapElements(arr) {
    return arr.reduce((acc, curr) => acc + curr, 0);
}

module.exports = { sumHeapElements };