Here is the Python code to solve the problem:

def find_min(heap):
    return heap[0]

def main():
    N = int(input().strip())
    heap = list(map(int, input().strip().split()))
    print(find_min(heap))

if __name__ == "__main__":
    main()

In this code, we first define a function `find_min` that takes a list of numbers as input and returns the minimum number. This is the only operation that does not require any additional space, so it is a O(1) operation.

The main function reads the number of elements N, and then the elements themselves. It calls `find_min` with the input heap and prints the result.

The `if __name__ == "__main__":` line ensures that the code is only run when the file is executed directly, and not when it is imported as a module. This is a common practice in Python, which ensures that the main function is only called when the script is executed directly, not when it is imported as a module.