# problem title : Euler's Theorem Evaluation
# Solve the stated task using standard input and standard output.
def phi(n: int) -> int:
    res = n
    p = 2
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            res -= res // p
        p += 1
    if n > 1:
        res -= res // n
    return res

def euler_pow(a: int, b: int, m: int) -> int:
    p = phi(m)
    exp = b % p
    return pow(a, exp, m)

if __name__ == '__main__':
    a, b, m = map(int, input().split())
    print(euler_pow(a, b, m))
