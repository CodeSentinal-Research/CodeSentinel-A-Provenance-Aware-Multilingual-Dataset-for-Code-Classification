def is_spy_number(n: int) -> bool:
    if n < 0:
        n = abs(n)
    digits = [int(d) for d in str(n)]
    sum_d = sum(digits)
    prod_d = 1
    for d in digits:
        prod_d *= d
    return sum_d == prod_d

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_spy_number(n) else "NO")