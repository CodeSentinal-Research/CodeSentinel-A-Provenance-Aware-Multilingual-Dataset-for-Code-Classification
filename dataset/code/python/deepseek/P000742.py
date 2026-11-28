Here is the Python code for the given problem:

def print_numbers(n):
    if n == 1:
        return
    else:
        print_numbers(n-1)
        print(n)

def main():
    n = int(input("Enter a number: "))
    print_numbers(n)

if __name__ == "__main__":
    main()

In this code, the function `print_numbers(n)` is a recursive function that prints the numbers from 1 to n. The base case for the recursion is when n is 1, and the recursive case is when n is not 1, in which case we call `print_numbers(n-1)`. This means we print the current number and then recursively call `print_numbers` on the number one less than the current number.

In the `main()` function, we get the input from the user, and then call the `print_numbers()` function with this input.

The `if __name__ == "__main__"` line is a common Python idiom for scripts that should only be executed if the file is run directly, not if it is imported as a module. This makes the `main()` function work as a standalone script.