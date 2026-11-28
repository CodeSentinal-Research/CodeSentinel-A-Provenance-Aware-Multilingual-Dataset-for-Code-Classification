Here is a Python code snippet that fulfills your requirements. It uses bitwise XOR operator to find the unique element in the sorted array.

def find_unique(arr):
    result = 0
    for num in arr:
        result ^= num
    return result

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    print(find_unique(arr))

In this code, the function `find_unique` takes a sorted array as input. It uses a bitwise XOR operator to XOR each element with the result. The final XOR operation will leave us with the unique element.

In the main function, it reads the number of elements in the array, then reads the array itself. Finally, it prints the unique element.

This code will work for the given constraints (1 ≤ N ≤ 1000).