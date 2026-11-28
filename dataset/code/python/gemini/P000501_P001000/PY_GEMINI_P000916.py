def count_derangements(n: int) -> int:
    if n == 0:
        return 1
    if n == 1:
        return 0
    prev2, prev1 = 1, 0
    for i in range(2, n + 1):
        curr = (i - 1) * (prev1 + prev2)
        prev2, prev1 = prev1, curr
    return prev1

if __name__ == '__main__':
    n = int(input())
    print(count_derangements(n))