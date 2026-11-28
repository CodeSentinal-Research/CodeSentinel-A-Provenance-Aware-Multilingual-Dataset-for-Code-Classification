function segregateElements(arr) {
    const pos = arr.filter(x => x >= 0);
    const neg = arr.filter(x => x < 0);
    const res = pos.concat(neg);
    for (let i = 0; i < arr.length; i++) arr[i] = res[i];
}

module.exports = { segregateElements };