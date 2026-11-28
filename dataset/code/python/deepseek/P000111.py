Here is the Python code for the given problem:

def find_second_largest(arr):
    max_val = max(arr)
    arr.remove(max_val)
    if max(arr) in arr:
        return max(arr)
    else:
        return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(find_second_largest(arr))

if __name__ == "__main__":
    main()

In this code, the `find_second_largest` function first finds the maximum value in the array, then removes this value from the array. If the maximum value is removed, the second largest value exists. If it is not, it returns -1.

The `main` function is the entry point of the program. It gets the input for the number of elements and the elements themselves. It then calls the `find_second_largest` function and prints the result.

Note: The `main` function is necessary because Python interprets `if __name__ == "__main__"` as a line to be run if this script is being run directly, not when it's imported as a module.