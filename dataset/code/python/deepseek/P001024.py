Here is a Python solution for the problem:

def process_heap(inputs):
    N, arr, i = inputs
    if i<N:
        left_child = 2*i + 1
        right_child = 2*i + 2
        if left_child < N:
            print(arr[left_child])
        else:
            print(-1)
        if right_child < N:
            print(arr[right_child])
        else:
            print(-1)

def main():
    N = int(input().strip())
    arr = [int(i) for i in input().strip().split()]
    i = int(input().strip())
    process_heap((N, arr, i))

if __name__ == "__main__":
    main()

In this code, the main function first reads the number of nodes (N), the array of nodes (arr), and the index of the node to process (i). Then it calls the `process_heap` function, which prints the left and right children of the node at index `i`.