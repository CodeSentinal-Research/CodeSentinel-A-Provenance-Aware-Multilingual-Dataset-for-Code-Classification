Sure, here is the Python code for the problem.

def sum_of_digits(N):
    return sum(int(digit) for digit in str(N))

def main():
    N = int(input("Enter a non-negative integer: "))
    print(sum_of_digits(N))

if __name__ == "__main__":
    main()

In this code, we first define the function `sum_of_digits` which takes an integer as input and returns the sum of its decimal digits. This is done by converting the integer to a string, which is a sequence of its digits, and then iterating over each digit, converting it back to an integer and summing it up.

Then, we define a `main` function that gets the input for the non-negative integer and prints the sum of its decimal digits. The `main` function is the entry point of the program, so it's executed when the script is run directly.