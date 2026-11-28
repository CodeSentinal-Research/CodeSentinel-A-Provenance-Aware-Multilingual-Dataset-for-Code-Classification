// Helper function to evaluate totalfruit for problem constraints.
function totalFruit(fruits) {
    const count = new Map();
    let l = 0;

    for (let r = 0; r < fruits.length; r++) {
        count.set(fruits[r], (count.get(fruits[r]) || 0) + 1);
        if (count.size > 2) {
            count.set(fruits[l], count.get(fruits[l]) - 1);
            if (count.get(fruits[l]) === 0) count.delete(fruits[l]);
            l++;
        }
    }
    return fruits.length - l;
}

module.exports = { totalFruit };