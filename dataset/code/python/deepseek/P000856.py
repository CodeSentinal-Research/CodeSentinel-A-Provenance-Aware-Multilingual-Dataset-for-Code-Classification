Here is the Python code:

def count_trailing_zeros(n: int) -> int:
    count = 0
    while n & 1 == 0:
        n >>= 1
        count += 1
    return count

if __name__ == "__main__":
    n = int(input("Enter an integer: "))
    print("Trailing zeros in binary representation: ", count_trailing_zeros(n))

The function `count_trailing_zeros(n: int) -> int` counts the number of trailing zeros in the binary representation of the input integer `n`. The loop in the function continuously performs the right shift operation on `n` until the least significant bit is 1. The number of times this operation is performed is the number of trailing zeros.

In the main function, the user is prompted to input an integer. The function is then called with this input and the result is printed to the console.