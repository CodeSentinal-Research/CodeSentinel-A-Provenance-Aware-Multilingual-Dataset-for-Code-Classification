# problem title : Count Valid Handshakes
# Solve the stated task using standard input and standard output.
def count_handshakes(n: int) -> int:
    # Catalan number C(n/2)
    if n % 2 == 1:
        return 0
    k = n // 2
    ans = 1
    for i in range(k):
        ans = ans * (2 * k - i) // (i + 1)
    return ans // (k + 1)

if __name__ == '__main__':
    n = int(input())
    print(count_handshakes(n))
