Here is the Python code:

def print_factors(n):
    for i in range(1, n + 1):
        if n % i == 0:
            print(i, end=" ")

def main():
    n = int(input("Enter a positive integer: "))
    if n < 1 or n > 1000:
        print("Invalid input. Please enter a positive integer between 1 and 1000.")
        return
    print_factors(n)

if __name__ == "__main__":
    main()

This program will ask the user to input a positive integer. It will then print all factors of the input integer. If the input is not a positive integer or is outside the range of 1 to 1000, it will print an error message and exit.