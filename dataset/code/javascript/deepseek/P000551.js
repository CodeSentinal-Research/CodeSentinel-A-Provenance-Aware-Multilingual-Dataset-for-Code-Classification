function generateBinary(n) {
    // Input validation
    if (n < 1 || n > 10 ^ 5) {
        throw new Error("Input should be between 1 and 10^5");
    }

    // Create an empty queue
    let queue = [];

    // Enqueue the first number
    queue.push({num: 1, bin: '1'});

    // Loop until queue is empty
    while (queue.length) {
        // Dequeue a number
        let {num, bin} = queue.shift();

        // Print the binary representation of the number
        console.log(bin);

        // If number is not the last number, enqueue the next number
        if (num < n) {
            queue.push({num: num + 1, bin: bin + '1'});
        }
    }
}