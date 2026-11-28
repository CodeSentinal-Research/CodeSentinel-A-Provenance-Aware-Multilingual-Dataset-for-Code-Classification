function heapHeightCalculation(N) {
    if (N < 1 || N > 10^9) {
        console.log('Invalid input. Please provide a value between 1 and 10^9.');
        return;
    }
    var height = 0;
    while (N > 1) {
        N = Math.floor(N / 2);
        height++;
    }
    console.log(height);
}
This JavaScript code defines a function called `heapHeightCalculation`. The function takes one parameter, `N`, which represents the number of nodes in the heap. The function first checks if `N` is less than 1 or greater than `10^9`, if so, it prints an error message and returns without doing anything else.

If `N` is valid, the function then initializes a variable `height` to 0. The function then enters a loop where it continuously divides `N` by 2 until it's less than 1. As it divides `N` by 2, it increments the `height` variable by 1.

The loop continues until `N` becomes less than 1, at which point the function prints the value of `height`.