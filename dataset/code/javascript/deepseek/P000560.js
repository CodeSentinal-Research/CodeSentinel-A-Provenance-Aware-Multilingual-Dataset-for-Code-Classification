function interleaveQueue(N, queue) {
    // Separate the queue into two halves
    const firstHalf = queue.splice(0, N / 2);
    const secondHalf = queue;

    // Interleave the two halves
    let interleavedQueue = [];
    for (let i = 0; i < N; i++) {
        if (i % 2 === 0) {
            interleavedQueue.push(firstHalf.shift());
        } else {
            interleavedQueue.push(secondHalf.shift());
        }
    }

    return interleavedQueue;
}

In this function, the queue is first split into two halves with the help of JavaScript's `splice()` method. Then, the two halves are interleaved together by using a `for` loop and the `%` operator to alternate between taking elements from the first and second half.