Here is the Python code for the given problem:

class MovingAverageStream:
    def __init__(self, size):
        self.size = size
        self.queue = []

    def next(self, val):
        self.queue.append(val)
        if len(self.queue) > self.size:
            self.queue.pop(0)
        if self.queue:
            return sum(self.queue) / len(self.queue)
        return 0

And here is a main function to test the above code:

def main():
    moving_average_stream = MovingAverageStream(3)
    for i in range(1, 11):
        print(f'Inserted: {i}, Current Average: {moving_average_stream.next(i)}')

if __name__ == '__main__':
    main()

In this code, we define a class `MovingAverageStream` which holds a queue of size `size`. For each incoming value `val`, we first add it to the queue. If the queue is larger than `size`, we remove the oldest element. If the queue is not empty, we calculate and return the current average. If the queue is empty, we return 0.

The `main` function is just a driver function that tests the above code by inserting values from 1 to 10, printing the current average for each insertion.