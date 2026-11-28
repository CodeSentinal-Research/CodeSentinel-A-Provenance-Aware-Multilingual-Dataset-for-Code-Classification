function isHappy(n) {
    let slow = n;
    let fast = n;
    do {
        slow = squareDigitsSum(slow);
        fast = squareDigitsSum(squareDigitsSum(fast));
    } while (slow !== fast)

    return slow === 1;
}

function squareDigitsSum(n) {
    let sum = 0;
    while (n) {
        let digit = n % 10;
        sum += digit * digit;
        n = Math.floor(n / 10);
    }
    return sum;
}

// Test the code
console.log(isHappy(19)); // Should print: YES
console.log(isHappy(16)); // Should print: NO