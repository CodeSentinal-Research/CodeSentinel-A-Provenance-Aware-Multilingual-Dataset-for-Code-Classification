# problem title : Distribute Identical Balls into Distinct Boxes
# Solve the stated task using standard input and standard output.
def stars_and_bars(n: int, k: int) -> int:
    # C(n + k - 1, k - 1)
    total = n + k - 1
    r = k - 1
    if r < 0 or r > total:
        return 0
    r = min(r, total - r)
    ans = 1
    for i in range(1, r + 1):
        ans = ans * (total - i + 1) // i
    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    print(stars_and_bars(n, k))
