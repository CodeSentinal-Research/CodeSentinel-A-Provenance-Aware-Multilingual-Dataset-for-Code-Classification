Sure, here is a simple Python solution for your problem:

def count_digits(n):
    if n == 0:
        return 1
    else:
        return len(str(n))

def main():
    n = int(input("Enter a non-negative integer: "))
    while n < 0:
        n = int(input("Invalid input, enter a non-negative integer: "))
    print("Number of digits: ", count_digits(n))

if __name__ == "__main__":
    main()

In this code, the `count_digits` function takes an integer `n` and returns the number of digits in `n`. If `n` is 0, it returns 1 because 0 has one digit. Otherwise, it converts `n` to a string and gets the length of the string, which is the number of digits in `n`.

The `main` function first asks for user input. It then checks if the input is valid (i.e., a non-negative integer). If the input is valid, it calls the `count_digits` function and prints the result. If the input is not valid, it prints an error message and asks for input again.

Please note that for large inputs (e.g., `10^18`), the time complexity of this program can be quite high. You may need to use a different approach for large inputs.