Here is a JavaScript solution for the given problem:

function sequentialDigits(low, high) {
    let queue = [...Array(10).keys()].map((_, i) => i);
    let result = [];

    while (queue.length) {
        let num = queue.shift();

        if (num >= low && num <= high) {
            result.push(num);
        }

        if (num % 10 + 1 < 10) {
            queue.push(num * 10 + (num % 10 + 1));
        }
    }

    result.sort((a, b) => a - b);
    return result;
}

console.log(sequentialDigits(10, 50));

This code first defines a queue of numbers that can be obtained from the digits of a number. It then starts popping the queue and checks if the number is within the given range. If it is, it pushes it to the result array.

If the number is not within the range, it appends the next number after the last digit to the queue. This process repeats until the queue is empty. Finally, it returns the result array sorted in ascending order.

The result is a list of all sequential digit numbers in the given range that are within the range [low, high].