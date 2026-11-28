Here is the Python code to solve the problem:

def xorOperation(n, nums):
    xor = 0
    for i in range(n):
        xor ^= nums[i]
    return xor

def main():
    n = int(input("Enter the number of elements in the array: "))
    nums = list(map(int, input("Enter the elements of the array: ").split()))
    print(xorOperation(n, nums))

if __name__ == "__main__":
    main()

In this code, we first define a function `xorOperation` that takes two arguments - the number of elements in the array and the array itself. This function iterates over the array and applies the XOR operation to all elements. Then it returns the result.

In the `main` function, we first ask for the number of elements in the array. Then we ask for the elements themselves. After that, we call the `xorOperation` function and print the result.

The `if __name__ == "__main__"` block is for Python's ability to run a code block if the file is run directly, but not if it's imported as a module. It's a common Python idiom.