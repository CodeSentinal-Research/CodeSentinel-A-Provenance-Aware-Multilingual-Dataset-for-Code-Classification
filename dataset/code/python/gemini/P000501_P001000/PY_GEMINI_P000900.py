def is_divisible_by_9(s: str) -> bool:
    total = sum(int(c) for c in s.strip() if c.isdigit())
    return total % 9 == 0

if __name__ == '__main__':
    s = input().strip()
    print("YES" if is_divisible_by_9(s) else "NO")