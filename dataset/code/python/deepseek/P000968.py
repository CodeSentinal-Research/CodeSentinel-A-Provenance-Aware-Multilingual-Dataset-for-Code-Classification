def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def solve(a, m, b, n):
    if a % m == b % m:
        return a % m, m
    else:
        return -1, -1

def merge_congruences(a, m, b, n):
    g = gcd(m, n)
    if a % g != b % g:
        return -1
    a_prime = a % m
    b_prime = b % n
    lcm = m * n // g
    merged_a = (a_prime - b_prime) % lcm
    if merged_a < 0:
        merged_a += lcm
    return merged_a, lcm

def main():
    a = int(input("Enter A: "))
    m = int(input("Enter M: "))
    b = int(input("Enter B: "))
    n = int(input("Enter N: "))
    result = merge_congruences(a, m, b, n)
    if result[0] == -1:
        print("No solution exists")
    else:
        print(f"The merged congruence is {result[0]} (mod {result[1]})")

if __name__ == "__main__":
    main()