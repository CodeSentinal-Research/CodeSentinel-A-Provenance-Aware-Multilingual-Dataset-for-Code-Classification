import heapq

def replace_root(input_heap, replacement_value):
    input_heap[0] = replacement_value

    heapq.heapify(input_heap)

def main():
    N = int(input().strip())
    input_heap = [int(item) for item in input().strip().split(' ')]
    replacement_value = int(input().strip())

    replace_root(input_heap, replacement_value)

    print(' '.join(map(str, input_heap)))

if __name__ == "__main__":
    main()