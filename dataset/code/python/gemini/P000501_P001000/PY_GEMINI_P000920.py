def min_max_digit(n: int):
    digits = [int(d) for d in str(abs(n))]
    return min(digits), max(digits)

if __name__ == '__main__':
    n = int(input())
    mn, mx = min_max_digit(n)
    print(f"{mn} {mx}")