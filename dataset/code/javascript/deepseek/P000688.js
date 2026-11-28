function countDigits(n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + countDigits(Math.floor(n / 10));
    }
}

console.log(countDigits(parseInt(prompt('Enter a non-negative integer: '))));