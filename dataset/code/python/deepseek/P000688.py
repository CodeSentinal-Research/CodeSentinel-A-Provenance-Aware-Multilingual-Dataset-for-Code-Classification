Here is the Python code:

def count_digits(n):
    if n == 0:
        return 1
    else:
        return len(str(n)) + count_digits(n // 10)

def main():
    n = int(input("Enter a non-negative integer: "))
    while not (0 <= n <= 10**18):
        print("Invalid input. Please enter a non-negative integer within the constraints.")
        n = int(input("Enter a non-negative integer: "))
    print("Number of digits: ", count_digits(n))

if __name__ == "__main__":
    main()

In this code, the function `count_digits` uses recursion to count the number of digits in the decimal representation of the given number. The base case of the recursion is when the number is 0, in which case it returns 1 (since the number of digits in 0 is 1). For other numbers, it calculates the length of the string representation of the number (since the number of digits in a number is the length of this string), and then recursively counts the digits in the number divided by 10 (since one digit is removed from the number when divided by 10).

The `main` function handles the input and input validation. It prompts the user to enter a non-negative integer within the constraints. If the input is not valid, it repeats the prompt until a valid input is given.

When the program is run, it will prompt the user to enter a non-negative integer and then print the number of digits in its decimal representation.