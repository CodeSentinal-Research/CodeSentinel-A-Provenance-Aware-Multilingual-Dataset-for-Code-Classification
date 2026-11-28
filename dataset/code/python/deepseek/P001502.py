Here's a Python code that uses a simple approach to solve the problem:

def minimumSwaps(arr):
    count = 0
    while arr != sorted(arr):
        index = arr.index(1)
        if index != len(arr) - 1:
            arr[index], arr[index + 1] = arr[index + 1], arr[index]
            count += 1
        else:
            arr.pop()
            count += 1
    return count

def main():
    N = int(input().strip())
    arr = [int(i) for i in input().strip().split()]
    print(minimumSwaps(arr))

main()

This code works by iterating through the array and swapping the first occurrence of a 1 with the last one. This is because the goal is to group all 1s together, and swapping the first occurrence would move it to the last possible location. After each swap, it increments a counter. This process continues until the array is sorted.

In the main function, it takes an input for the number of elements in the array, and the array itself. It then calls the `minimumSwaps` function to print the minimum number of swaps required.