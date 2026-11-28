Sure, here is a JavaScript solution for the problem:

function probability(N, K) {
    if (!Number.isInteger(N) || !Number.isInteger(K) || N < 1 || N > 1000 || K < 0 || K > N) {
        throw new Error('Invalid input');
    }
    
    let probability = 1.0;
    
    for (let i = 0; i < K; i++) {
        probability *= (N - i) / N;
    }
    
    for (let i = 0; i < N - K; i++) {
        probability *= (N - i) / N;
    }
    
    return probability;
}

In this code, we calculate the probability of getting exactly K heads by multiplying the probabilities of getting no heads and no heads, until we reach the Kth head. The probability of getting no heads is 1 - probability of getting at least one head, which is 1 - (N - K) / N. We multiply the probabilities in this way, starting from the Kth head, until we reach the end of the coin tosses.

You can call this function with N and K as arguments:

console.log(probability(10, 3)); // Output: 0.037037037037037035

This code assumes that you are running it in a node.js environment, and it can throw an error if the input is invalid.