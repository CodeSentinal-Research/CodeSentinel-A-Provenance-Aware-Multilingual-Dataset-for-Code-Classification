def is_divisible_by_11(s: str) -> bool:
    s = s.strip()
    odd_sum = sum(int(s[i]) for i in range(0, len(s), 2))
    even_sum = sum(int(s[i]) for i in range(1, len(s), 2))
    return abs(odd_sum - even_sum) % 11 == 0

if __name__ == '__main__':
    s = input().strip()
    print("YES" if is_divisible_by_11(s) else "NO")