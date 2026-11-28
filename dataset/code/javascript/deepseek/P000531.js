Here is the JavaScript code for the given problem:

class RecentCounter {
    constructor() {
        this.queue = [];
        this.index = 0;
    }

    ping(t) {
        // Remove old elements from the queue
        while (this.queue[this.index - 1] < t - 3000) {
            this.queue.shift();
            this.index--;
        }

        // Add a new request into the queue
        this.queue.push(t);
        this.index++;

        // Return the current number of requests
        return this.queue.length;
    }
}
This code defines a class `RecentCounter` which uses a deque (double-ended queue) to store the timestamps. The deque is used to efficiently remove old elements from the front of the queue. Each request is added to the end of the deque. The number of requests is then just the length of the deque. This solution is efficient as the time complexity is O(1) for each `ping` operation.