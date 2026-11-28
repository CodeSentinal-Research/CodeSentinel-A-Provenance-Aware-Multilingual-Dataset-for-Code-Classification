def sum_of_gp(a: float, r: float, n: int) -> float:
    if n <= 0:
        return 0.0
    if r == 1.0:
        return a * n
    return a * (1.0 - (r ** n)) / (1.0 - r)

if __name__ == '__main__':
    a, r, n = input().split()
    print(f"{sum_of_gp(float(a), float(r), int(n)):.2f}")