Here is the JavaScript code for the problem:

function knapSack(W, wt, val, n) {
    let i, w;
    let K = new Array(W + 1);
    
    for(i = 0; i <= W; i++)
        K[i] = 0;
        
    for(i = 1; i <= n; i++) {
        w = wt[i];
        for(w = w; w <= W; w++) {
            K[w] = Math.max(K[w], K[w-w] + val[i]);
        }
    }
    
    return K[W];
}

function main() {
    let N = prompt("Enter the number of items:");
    let W = prompt("Enter the knapsack capacity:");
    W = parseInt(W);
    N = parseInt(N);

    let wt = [];
    let val = [];

    for(let i = 0; i < N; i++) {
        wt[i] = prompt(`Enter weight of item ${i + 1}:`);
        val[i] = prompt(`Enter value of item ${i + 1}:`);
    }

    let result = knapSack(W, wt, val, N);
    console.log(`The maximum obtainable value is: ${result}`);
}

main();

The `knapSack` function finds the maximum value that can be obtained with fractions of items taken from the given items. It uses the concept of Dynamic Programming.

The `main` function takes the number of items, knapsack capacity, and items' weights and values from the user, calls the `knapSack` function to find the maximum value, and prints the result.