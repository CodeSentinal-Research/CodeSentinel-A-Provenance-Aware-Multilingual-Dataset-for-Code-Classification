Here is the Python code for the given problem:

def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True

def main():
    n = int(input("Enter a positive integer: "))
    if is_prime(n):
        print("Prime")
    else:
        print("Not Prime")

if __name__ == "__main__":
    main()

In this code, the `is_prime` function checks if a given number is prime by iterating from 2 to sqrt(n) and checking if n is divisible by the current number. If n is divisible by any number in this range, then n is not prime.

The `main` function is the entry point of the program. It reads an integer from the standard input, checks if it is prime, and prints the corresponding message.

The `if __name__ == "__main__":` is a special statement in Python, which ensures that the main function is only called when the script is executed directly (not imported as a module), not when it's imported as a module in another script.