Here is the Python code for the Chinese Remainder Theorem Solver. This code uses the Extended Euclidean Algorithm to compute the greatest common divisor and then uses it to solve the system of congruences.

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        gcd, x, y = extended_gcd(b % a, a)
        return gcd, y - (b // a) * x, x

def chinese_remainder(modulus, remainder):
    M = 1
    for m in modulus:
        M *= m

    res = 0
    for i in range(len(modulus)):
        Mi = M // modulus[i]
        res += remainder[i] * Mi * extended_gcd(modulus[i], M)[1] * M
    return res % M

def main():
    N = int(input())
    modulus = list(map(int, input().split()))
    remainder = list(map(int, input().split()))
    print(chinese_remainder(modulus, remainder))

if __name__ == "__main__":
    main()

In this code, the `extended_gcd` function computes the greatest common divisor of two numbers a and b. The `chinese_remainder` function computes the smallest non-negative integer that satisfies all congruences. The `main` function reads the input, computes the solution, and prints it.