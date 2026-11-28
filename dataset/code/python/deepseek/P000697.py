Here is the Python code:

def is_prime(n, i=2):
    if n <= 2:
        return True if n == 2 else False
    if n % i == 0:
        return False
    if i * i > n:
        return True

    return is_prime(n, i + 1)

def main():
    n = int(input("Enter a positive integer: "))
    if is_prime(n):
        print("True")
    else:
        print("False")

if __name__ == "__main__":
    main()

This program uses recursion to check if a number is prime. It starts with the recursion function `is_prime()` which checks divisibility up to the square root of `n`. If `n` is divisible by `i`, then `n` is not a prime number. If `n` is not divisible by `i`, then `n` is a prime number, otherwise `i` increments and the recursion goes deeper.

Then in the main function, it prompts the user to input a number. It then calls the `is_prime()` function with the input number as the argument and prints out the result.