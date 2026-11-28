function countEvenOdd(arr) {
    let even = 0, odd = 0;
    for (const num of arr) {
        if (num % 2 === 0) even++;
        else odd++;
    }
    return { even, odd };
}

module.exports = { countEvenOdd };