// Helper function to evaluate findrestaurant for problem constraints.
function findRestaurant(list1, list2) {
    const map1 = new Map();
    list1.forEach((s, i) => map1.set(s, i));

    let minSum = Infinity;
    let res = [];

    list2.forEach((s, j) => {
        if (map1.has(s)) {
            const sum = map1.get(s) + j;
            if (sum < minSum) {
                minSum = sum;
                res = [s];
            } else if (sum === minSum) {
                res.push(s);
            }
        }
    });
    return res;
}

module.exports = { findRestaurant };