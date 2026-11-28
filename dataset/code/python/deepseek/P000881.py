Here is the Python code for the problem. This code uses a simple approach of counting the number of digits by converting the integer to a string and then getting the length of the string.

def count_digits(n):
    return len(str(n))

def main():
    n = int(input("Enter an integer: "))
    while not(0 <= n <= 10**18):
        print("Invalid input. Please enter an integer between 0 and 10^18.")
        n = int(input("Enter an integer: "))
    print("The number of digits is:", count_digits(n))

if __name__ == "__main__":
    main()

In this code, the `count_digits` function takes an integer `n` as an argument, converts it to a string and returns the length of the string. The `main` function handles the input and output, asks for the user's input and ensures that the input is within the given constraints. If the input is not within the constraints, it continues to prompt the user for input until a valid input is provided.