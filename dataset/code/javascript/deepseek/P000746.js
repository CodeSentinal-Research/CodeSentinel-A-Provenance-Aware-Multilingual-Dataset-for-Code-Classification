Here is the recursive implementation of the Josephus problem using JavaScript:

function josephus(N, K) {
    if (N == 1) {
        return 1;
    } else {
        return (josephus(N - 1, K) + K - 1) % N + 1;
    }
}

This function uses the recursive rule of the Josephus problem: the person at position `x` is eliminated when `x + K - 1` is picked up. 

The `% N` at the end of the equation ensures that `x` remains within the range of 1 to `N`. 

Also, the base case is `N == 1` when there is only one person left. The function returns the position of the survivor.

To use this function, you would pass the parameters `N` and `K` as arguments to the function:

console.log(josephus(5, 2)); // Outputs: 3

This will return `3` which is the position of the survivor.