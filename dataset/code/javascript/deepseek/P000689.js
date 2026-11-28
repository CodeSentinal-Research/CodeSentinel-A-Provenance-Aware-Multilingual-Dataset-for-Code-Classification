function productDigits(n) {
    if (n === 0) {
        return 0;
    }
    let lastDigit = n % 10;
    return lastDigit * productDigits(Math.floor(n / 10));
}

console.log(productDigits(1234)); // 24
console.log(productDigits(5678)); // 30