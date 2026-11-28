Here is a Python solution using the Euclidean algorithm to find the greatest common divisor (GCD) of the moduli, and then using the Chinese Remainder Theorem (CRT) to find the smallest non-negative solution. 

def find_crt(n, moduli):
    def gcd(a, b):
        if b == 0:
            return a
        else:
            return gcd(b, a % b)

    mod = reduce(lambda x, y: x * y // gcd(x, y), moduli)
    return (sum(m * pow(mod // m, -1, m) for m in moduli) - sum(c * pow(mod // m, -1, m) for c in congruences)) % mod


def main():
    N = int(input().strip())
    congruences = list(map(int, input().strip().split()))
    moduli = list(map(int, input().strip().split()))

    if all(c % m == 0 for c, m in zip(congruences, moduli)):
        print(-1)
    else:
        print(find_crt(N, moduli))


if __name__ == "__main__":
    main()

In this code, the `gcd` function uses the Euclidean algorithm to find the greatest common divisor of two numbers. The `find_crt` function finds the smallest non-negative solution using the Chinese Remainder Theorem. It first calculates the product of all moduli, then calculates the inverse for each modulus modulo every congruence. Finally, it calculates the sum of all congruences multiplied by their inverses modulo the product of all moduli. The result is the sum of all congruences modulo the product of all moduli, which is the smallest non-negative solution.

The `main` function reads the number of congruences and the moduli, then checks if all congruences can be divided evenly by all moduli. If not, it prints the smallest non-negative solution. Otherwise, it calculates and prints the smallest non-negative solution.