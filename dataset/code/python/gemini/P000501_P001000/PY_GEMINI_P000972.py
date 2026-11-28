import math

def prob_heads(n: int, k: int, p: float) -> float:
    # C(n, k) * p^k * (1 - p)^(n - k)
    if k < 0 or k > n:
        return 0.0
    ways = math.comb(n, k)
    return ways * (p ** k) * ((1.0 - p) ** (n - k))

if __name__ == '__main__':
    n, k = map(int, input().split())
    p = float(input())
    print(f"{prob_heads(n, k, p):.6f}")