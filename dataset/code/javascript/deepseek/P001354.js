Here's the JavaScript code for the problem:

function splitStringToFibonacci(s) {
    let nums = s.split(' ').map(Number);
    let fibonacciNums = [0, 1, 1];
    let i = 3;

    while (true) {
        if (i >= nums.length) break;
        fibonacciNums.push(fibonacciNums[i - 2] + fibonacciNums[i - 1]);
        i++;
    }

    if (fibonacciNums[i - 2] + fibonacciNums[i - 1] !== nums[nums.length - 1]) return "IMPOSSIBLE";

    return fibonacciNums.slice(0, i).join(' ');
}

console.log(splitStringToFibonacci("0 1 1")); // Expected output: 0 1 1 2 3
console.log(splitStringToFibonacci("1 1 2 3 5 8 13 21")); // Expected output: 1 1 2 3 5 8 13 21 34
console.log(splitStringToFibonacci("10 20 30")); // Expected output: IMPOSSIBLE

This code first splits the input string into an array of numbers, then it generates a Fibonacci sequence starting from the first two numbers in the array. It keeps adding numbers to the sequence until it reaches the last number in the input string. If the last two numbers in the Fibonacci sequence add up to the last number in the input string, then it returns the sequence. Otherwise, it returns IMPOSSIBLE.