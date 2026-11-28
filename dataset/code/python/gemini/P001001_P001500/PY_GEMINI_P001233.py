from typing import List

def fractional_knapsack(w: int, values: List[int], weights: List[int]) -> float:
    items = sorted(zip(values, weights), key=lambda x: x[0] / x[1], reverse=True)
    total_val = 0.0
    capacity = w

    for val, wt in items:
        if capacity >= wt:
            total_val += val
            capacity -= wt
        else:
            total_val += val * (capacity / wt)
            break

    return total_val

if __name__ == '__main__':
    n, w = map(int, input().split())
    values = list(map(int, input().split()))
    weights = list(map(int, input().split()))
    print(f"{fractional_knapsack(w, values, weights):.6f}")