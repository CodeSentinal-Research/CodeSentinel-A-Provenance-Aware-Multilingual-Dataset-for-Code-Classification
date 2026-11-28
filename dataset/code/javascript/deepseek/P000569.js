function reverseQueue(N, QueueElements) {
    if (N < 1 || N > 100000) {
        throw new Error('Invalid N');
    }

    if (!Array.isArray(QueueElements)) {
        throw new Error('Invalid QueueElements');
    }

    const queue = new Array(N);
    queue.push(...QueueElements);
    let start = 0;
    let end = N - 1;

    while (start < end) {
        [queue[start], queue[end]] = [queue[end], queue[start]];
        start++;
        end--;
    }

    return queue;
}