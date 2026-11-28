def is_armstrong(n: int) -> bool:
    digits = [int(d) for d in str(n)]
    k = len(digits)
    return sum(d ** k for d in digits) == n

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_armstrong(n) else "NO")