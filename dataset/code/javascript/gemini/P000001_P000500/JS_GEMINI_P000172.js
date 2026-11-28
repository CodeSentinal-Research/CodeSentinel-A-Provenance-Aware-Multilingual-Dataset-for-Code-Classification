function segregateEvenOdd(arr) {
    const evens = arr.filter(x => x % 2 === 0).sort((a, b) => a - b);
    const odds = arr.filter(x => x % 2 !== 0).sort((a, b) => a - b);
    const res = evens.concat(odds);
    for (let i = 0; i < arr.length; i++) arr[i] = res[i];
}

module.exports = { segregateEvenOdd };