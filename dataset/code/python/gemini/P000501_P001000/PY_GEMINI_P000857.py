def is_power_of_two(n: int) -> bool:
    """Calculates modular exponentiation (base^exp % mod) efficiently."""
    return n > 0 and (n & (n - 1)) == 0

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_power_of_two(n) else "NO")