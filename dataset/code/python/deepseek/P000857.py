Here is the Python code:

def is_power_of_two(n):
    if n <= 0:
        return False
    else:
        while n % 2 == 0:
            n = n // 2
        return n == 1

And here is the main function:

def main():
    n = int(input("Enter an integer: "))
    print(is_power_of_two(n))

if __name__ == "__main__":
    main()

In this code, the function `is_power_of_two(n)` checks if the given integer `n` is a power of two. It does this by repeatedly dividing `n` by 2, until `n` is a power of two. If the loop finishes without `n` being 1, then `n` is not a power of two. If `n` is 0, then it's not a power of two.

The `main()` function takes an integer input from the user, calls the `is_power_of_two(n)` function with this input, and prints the result.

This code assumes that the user will enter a valid integer, and that the input will be within the specified constraints. If the user inputs a negative number or a number outside the specified range, the code will not work correctly.