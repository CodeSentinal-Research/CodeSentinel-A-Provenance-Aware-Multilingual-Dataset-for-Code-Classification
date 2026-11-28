def min_days_to_buy_food(s: int, n: int, m: int) -> int:
    total_food_needed = s * m
    if (n - m) * 6 < m and s > 6:
        return -1
    if m > n:
        return -1
    return (total_food_needed + n - 1) // n

if __name__ == '__main__':
    s, n, m = map(int, input().split())
    print(min_days_to_buy_food(s, n, m))