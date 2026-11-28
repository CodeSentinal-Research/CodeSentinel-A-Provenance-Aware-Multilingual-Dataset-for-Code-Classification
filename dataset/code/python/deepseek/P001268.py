Sure, I will provide a Python solution for the problem. I'll use a priority queue to solve this problem. The priority queue is a data structure that can give us the maximum element in O(1) time complexity.

Here is the code:

import heapq

def maxEvents(start, end):
    events = sorted(zip(end, start))
    end_day = max(end)

    current_day, counter = events[0][0], 0

    heap = []

    for event in events:
        if current_day < event[1]:
            heapq.heappush(heap, event[1])
        else:
            heapq.heappushpop(heap, event[1])

        if current_day == event[0]:
            counter += 1

        current_day -= 1

    return counter

def main():
    n = int(input().strip())

    start = [int(input().strip()) for _ in range(n)]
    end = [int(input().strip()) for _ in range(n)]

    print(maxEvents(start, end))

if __name__ == "__main__":
    main()

This code will get the number of events from the input, get the start and end days, call the function `maxEvents`, and print the result. Please note that this code assumes that the start day is smaller than the end day. If the start day is larger, you should sort the events by end day first and then start day.