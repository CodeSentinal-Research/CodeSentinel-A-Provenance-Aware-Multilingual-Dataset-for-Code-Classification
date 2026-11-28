def sum_of_ap(a: float, d: float, n: int) -> float:
    if n <= 0:
        return 0.0
    return (n / 2.0) * (2.0 * a + (n - 1) * d)

if __name__ == '__main__':
    a, d, n = input().split()
    print(f"{sum_of_ap(float(a), float(d), int(n)):.2f}")