def is_kth_bit_set(n: int, k: int) -> bool:
    return (n & (1 << k)) != 0

if __name__ == '__main__':
    n, k = map(int, input().split())
    print("YES" if is_kth_bit_set(n, k) else "NO")