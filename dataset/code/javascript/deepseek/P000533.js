Sure, here is the JavaScript code which implements the Moving Average from Data Stream:

class MovingAverage {
    constructor(size) {
        this.queue = [];
        this.sum = 0;
        this.size = size;
    }

    next(val) {
        if (this.queue.length === this.size) {
            this.sum -= this.queue.shift();
        }
        this.queue.push(val);
        this.sum += val;
        return this.sum / Math.min(this.size, this.queue.length);
    }
}

let ma = new MovingAverage(3);
console.log(ma.next(1)); // 1
console.log(ma.next(2)); // 1.5
console.log(ma.next(3)); // 2
console.log(ma.next(4)); // 3

In this code, `MovingAverage` is a class that takes an `size` argument. It keeps an array `queue` that stores the last `size` integers, and a `sum` variable that stores the sum of these integers. When a new integer is inserted, it is added to the `queue` and the `sum`. If the `queue` is full (i.e., it's length is equal to the `size`), the first element is removed from the `queue` and subtracted from the `sum`. Finally, the moving average is calculated as the sum divided by the number of elements in the `queue`.

Please note that the `next()` method of the `MovingAverage` class takes an integer `val` as input. The method first checks if the `queue` is full, and if so, removes the first element from the `queue` and subtracts it from the `sum`. Then, it adds the new integer to the `queue` and adds it to the `sum`. Finally, it calculates and returns the moving average as the sum divided by the number of elements in the `queue`.