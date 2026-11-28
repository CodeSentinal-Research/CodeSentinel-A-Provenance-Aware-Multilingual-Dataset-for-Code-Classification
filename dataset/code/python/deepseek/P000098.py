Here is the Python code for the problem.

def is_prime(n):
    if n == 1:
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

def sum_of_primes(n):
    sum_primes = 0
    for i in range(2, n + 1):
        if is_prime(i):
            sum_primes += i
    return sum_primes

def main():
    n = int(input("Enter a positive integer: "))
    while n < 1 or n > 10000:
        print("Invalid input!")
        n = int(input("Enter a positive integer: "))
    print("The sum of primes less than or equal to", n, "is", sum_of_primes(n))

if __name__ == "__main__":
    main()

This code first checks if the number is prime or not using the `is_prime` function. Then, it iterates from 2 to N (inclusive) using the `sum_of_primes` function. The `main` function handles the user input and checks if the input is valid. If the input is not valid, it will keep asking for input until a valid one is given.