Here is a Python solution for the problem using list as a queue.

def solve(N, Queue, K):
    K = K % N
    Queue = Queue[K:] + Queue[:K]
    return Queue

def main():
    N = int(input().strip())
    Queue = list(map(int, input().strip().split()))
    K = int(input().strip())
    print(solve(N, Queue, K))

if __name__ == "__main__":
    main()

In this code, we first get the input for N, Queue and K. Then we calculate the K mod N because in a circle the number of rotations is equivalent to the number of shifts in a clockwise rotation.

Next, we use slicing to rotate the queue by K positions to the left. The slicing operation generates a new list where the elements at indices K through N-1 are moved to the start of the list, and the elements at indices 0 through K-1 are moved to the end of the list.

Finally, we print the rotated queue.