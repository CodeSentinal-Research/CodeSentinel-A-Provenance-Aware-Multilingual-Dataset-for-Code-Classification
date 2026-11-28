Here's the JavaScript code for the problem:

function fibonacci(N) {
    if (N === 0) return 0;
    if (N === 1) return 1;
    return fibonacci(N - 1) + fibonacci(N - 2);
}

This function uses recursion to calculate the N-th Fibonacci number. The base cases are 0 and 1, for which the function returns the number. For any other number, the function calls itself with the parameters N - 1 and N - 2, and returns the sum of these two calls. This results in a sequence of calculating the Fibonacci numbers, starting from the first two numbers in the sequence.