def circular_arrangements(n: int) -> int:
    if n <= 1:
        return 1
    ans = 1
    for i in range(1, n):
        ans *= i
    return ans

if __name__ == '__main__':
    n = int(input())
    print(circular_arrangements(n))