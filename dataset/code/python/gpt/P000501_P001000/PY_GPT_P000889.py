# problem title : Prime Number Check
# Solve the stated task using standard input and standard output.
def is_prime(n: int) -> bool:
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_prime(n) else "NO")
