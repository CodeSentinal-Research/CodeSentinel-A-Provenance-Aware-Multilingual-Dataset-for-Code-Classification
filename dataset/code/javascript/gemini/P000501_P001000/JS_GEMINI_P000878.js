// Helper function to evaluate subarraybitwiseors for problem constraints.
function subarrayBitwiseORs(arr) {
    const res = new Set();
    let cur = new Set();
    for (const x of arr) {
        const next = new Set([x]);
        for (const y of cur) {
            next.add(x | y);
        }
        cur = next;
        for (const val of cur) {
            res.add(val);
        }
    }
    return res.size;
}

module.exports = { subarrayBitwiseORs };