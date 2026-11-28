# problem title : Check Divisibility by 3
# Solve the stated task using standard input and standard output.
def is_divisible_by_3(s: str) -> bool:
    total = sum(int(c) for c in s.strip() if c.isdigit())
    return total % 3 == 0

if __name__ == '__main__':
    s = input().strip()
    print("YES" if is_divisible_by_3(s) else "NO")
