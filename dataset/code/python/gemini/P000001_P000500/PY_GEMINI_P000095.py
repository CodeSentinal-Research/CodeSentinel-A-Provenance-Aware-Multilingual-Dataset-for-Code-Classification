def is_neon_number(n: int) -> bool:
    if n < 0:
        return False
    sq = n * n
    sum_digits = sum(int(digit) for digit in str(sq))
    return sum_digits == n

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_neon_number(n) else "NO")