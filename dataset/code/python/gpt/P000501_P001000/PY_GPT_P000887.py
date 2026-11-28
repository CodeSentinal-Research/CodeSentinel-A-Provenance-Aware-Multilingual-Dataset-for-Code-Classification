# problem title : Neon Number
# Solve the stated task using standard input and standard output.
def is_neon(n: int) -> bool:
    sq = n * n
    return sum(int(d) for d in str(sq)) == n

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_neon(n) else "NO")
