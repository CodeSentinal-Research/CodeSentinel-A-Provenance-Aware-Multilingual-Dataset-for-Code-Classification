Here is the Python code for the problem:

def is_valid_heap(initial_array, updates):
    current_array = initial_array[:]
    for update in updates:
        index, value = map(int, update.split())
        current_array[index - 1] = value
        while index > 0 and current_array[index - 1] < current_array[(index - 1) // 2]:
            current_array[index], current_array[(index - 1) // 2] = (current_array[(index - 1) // 2], current_array[index])
            index = (index - 1) // 2
    return current_array == sorted(initial_array)

def main():
    N, Q = map(int, input().split())
    initial_array = list(map(int, input().split()))
    updates = [input() for _ in range(Q)]
    if is_valid_heap(initial_array, updates):
        print('VALID')
    else:
        print('INVALID')

if __name__ == '__main__':
    main()

This code first reads the number of elements `N` and the number of updates `Q`, and the initial array. Then it reads the updates and checks if the final array is valid according to the heap property. It prints VALID if the final array is valid, and INVALID otherwise.