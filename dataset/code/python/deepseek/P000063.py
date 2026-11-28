Here is the Python code that solves the problem:

def print_prime_numbers(L, R):
    for num in range(L, R + 1):
        if num > 1:
            for i in range(2, num):
                if (num % i) == 0:
                    break
            else:
                print(num)

def main():
    L = int(input("Enter the lower limit: "))
    R = int(input("Enter the upper limit: "))
    print_prime_numbers(L, R)

if __name__ == "__main__":
    main()

In this code, we first define a function `print_prime_numbers` that iterates over all numbers in the range from `L` to `R` (inclusive). For each number, it checks if the number is greater than 1 and if it is not divisible by any number in the range from 2 to the number itself (exclusive). If the number is not divisible by any number in this range, then it's a prime number and we print the number.

Then we define a `main` function that handles the input and calls `print_prime_numbers`. We use the `input` function to read the lower and upper limits from the user, and convert them to integers.

Finally, we run the `main` function if this script is run as the main program.