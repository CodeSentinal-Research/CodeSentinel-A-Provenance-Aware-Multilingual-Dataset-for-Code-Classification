Here is a Python solution using a Heap data structure. The heapify method is used to rebuild the heap from a given list, and the heappushpop method is used to extract the maximum element from the heap and push a new element into the heap.

import heapq

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    heapq.heapify(arr)

    while len(arr) > 1:
        largest = heapq.heappop(arr)
        print(largest, end=' ')
        largest = heapq.heappop(arr)
        print(largest, end=' ')
        heapq.heappush(arr, largest)
    print(arr[0])

if __name__ == "__main__":
    main()

In this code, the main function first gets the number of elements in the array (n) and the array itself. It then heapifies the array and starts a loop that continues until there's only one element left in the array (which is the root of the heap). In each iteration of the loop, it pops the two largest elements from the heap and pushes them back into the heap. It then prints the remaining root of the heap.