# problem title : Next Prime Number
# Solve the stated task using standard input and standard output.
def is_prime(n: int) -> bool:
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def next_prime(n: int) -> int:
    cand = n + 1
    while not is_prime(cand):
        cand += 1
    return cand

if __name__ == '__main__':
    n = int(input())
    print(next_prime(n))
