import math

def prime_factors(n):
    factors = []
    while n % 2 == 0:
        factors.append(2)
        n = n / 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            factors.append(i)
            n = n / i
    if n > 2:
        factors.append(n)
    return factors

def main(n):
    factors = prime_factors(n)
    print(factors)

if __name__ == "__main__":
    n = int(input("Enter an integer: "))
    main(n)

In this code, the `prime_factors` function calculates the prime factors of a given number. The while loop is used to divide the number by 2 until it is no longer divisible by 2, then the for loop is used to divide the number by odd numbers starting from 3. If the remaining number is greater than 2, it is added as a prime factor to the list. The `main` function takes an integer as input, calculates the prime factors, and prints them.

The `if __name__ == "__main__":` line ensures the program starts only when this script is run directly, not when it is imported as a module in another script.

The `input` function is used to get the user's input, and the `int` function is used to convert the user's input to an integer.