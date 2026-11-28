def sqrt_newton(n: float, epsilon: float = 1e-7) -> float:
    if n < 0:
        raise ValueError("Cannot calculate square root of negative number.")
    if n == 0 or n == 1:
        return float(n)
    x = n
    while True:
        root = 0.5 * (x + (n / x))
        if abs(root - x) < epsilon:
            return root
        x = root

if __name__ == '__main__':
    n = float(input())
    print(f"{sqrt_newton(n):.6f}")