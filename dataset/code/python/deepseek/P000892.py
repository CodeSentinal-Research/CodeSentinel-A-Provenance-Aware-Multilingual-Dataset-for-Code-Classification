Here is the Python code for the problem:

def prime_factorization(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def main():
    n = int(input())
    print(prime_factorization(n))

if __name__ == "__main__":
    main()

In this code, the function `prime_factorization` takes an integer `n` as input and returns a list of its prime factors. It uses the algorithm known as the trial division method to find the prime factors of `n`. The process continues until `i` squared is greater than `n`, at which point `i` is incremented and the loop continues. If `n` is still greater than 1 after the loop, `n` is appended to the list of factors because it is a prime factor.

The `main` function is the entry point of the program. It reads an integer from the input, calls the `prime_factorization` function with this integer, and prints the returned list of factors.