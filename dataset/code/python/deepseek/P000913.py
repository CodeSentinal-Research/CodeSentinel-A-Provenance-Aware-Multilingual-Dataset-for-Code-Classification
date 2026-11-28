Here is the Python code with input handling.

def binomial_coefficient_mod_prime(n, r, p):
    fact_n = 1
    for i in range(1, n + 1):
        fact_n = (fact_n * i) % p

    fact_r = 1
    for i in range(1, r + 1):
        fact_r = (fact_r * i) % p

    fact_n_r = 1
    for i in range(1, (n - r) + 1):
        fact_n_r = (fact_n_r * i) % p

    ncr = (fact_n * fact_r) % p * fact_n_r
    return ncr

def main():
    n = int(input("Enter the value of n: "))
    r = int(input("Enter the value of r: "))
    p = int(input("Enter the value of p: "))

    print(binomial_coefficient_mod_prime(n, r, p))

if __name__ == "__main__":
    main()

This program first calculates the factorial of n, r, and n-r and then computes nCr mod p.