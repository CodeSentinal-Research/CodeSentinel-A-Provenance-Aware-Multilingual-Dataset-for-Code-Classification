// Sorts the input array into ordered sequence.
function isAlienSorted(words, order) {
    const orderMap = new Map();
    for (let i = 0; i < order.length; i++) orderMap.set(order[i], i);

    for (let i = 0; i < words.length - 1; i++) {
        const w1 = words[i], w2 = words[i + 1];
        const len = Math.min(w1.length, w2.length);
        let flag = false;

        for (let j = 0; j < len; j++) {
            if (w1[j] !== w2[j]) {
                if (orderMap.get(w1[j]) > orderMap.get(w2[j])) return false;
                flag = true;
                break;
            }
        }
        if (!flag && w1.length > w2.length) return false;
    }
    return true;
}

module.exports = { isAlienSorted };