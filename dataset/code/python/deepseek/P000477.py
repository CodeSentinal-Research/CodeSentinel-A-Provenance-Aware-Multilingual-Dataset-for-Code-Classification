Here is the Python code with the main function and input handling:

def find_pivot(arr):
    left_sum = 0
    right_sum = sum(arr)
    for i, num in enumerate(arr):
        right_sum -= num
        if left_sum == right_sum:
            return i
        left_sum += num
    return -1

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    print(find_pivot(arr))

if __name__ == "__main__":
    main()

The `find_pivot` function calculates the sum of all elements in the array and subtracts the current element. If the sum of all elements is equal to the sum of the remaining elements after subtracting the current element, this means that the current element is the pivot index.

The `main` function reads the number of elements N and the array from the input, calls the `find_pivot` function and prints the result.