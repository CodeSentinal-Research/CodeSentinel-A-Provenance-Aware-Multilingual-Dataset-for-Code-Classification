function solve(N, Queue, K) {
    // Handle invalid inputs
    if (N < 1 || N > 100000 || Queue.length !== N || Queue.length < 0 || K < 0 || K >= Queue.length) {
        throw new Error('Invalid input');
    }

    // Rotate the queue to the left by K positions
    for (let i = 0; i < K; i++) {
        Queue.push(Queue.shift());
    }

    return Queue;
}