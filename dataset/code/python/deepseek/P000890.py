def count_primes(n):
    is_prime = [True] * (n + 1)
    p = 2
    while p**2 <= n:
        if is_prime[p]:
            for i in range(p**2, n+1, p):
                is_prime[i] = False
        p += 1

    return sum(is_prime) - 2  

def main():
    n = int(input())
    print(count_primes(n))

if __name__ == "__main__":
    main()