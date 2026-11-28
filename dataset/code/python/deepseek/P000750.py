Here is the Python code for the problem:

def print_lexicographical(n):
    if n == 0:
        return
    else:
        for i in range(10):
            print_lexicographical(n * 10 + i)

def main():
    n = int(input())
    print_lexicographical(n)

if __name__ == "__main__":
    main()

This Python program is designed to solve the lexicographical order problem. It uses recursion to print the numbers from 1 to N in lexicographical order. The recursion works by creating a new number by appending each digit from 0 to 9 to the current number, up to N. This is done by using a for loop to iterate over each digit from 0 to 9, and for each digit, it recursively calls the function to create the new number.

The main function reads the integer N from the user, and then calls the function with N as the argument.

To run the program, replace `n = 5432` with the desired value for N.