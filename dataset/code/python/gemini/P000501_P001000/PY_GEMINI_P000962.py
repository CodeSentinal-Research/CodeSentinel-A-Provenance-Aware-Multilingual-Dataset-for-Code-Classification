def frobenius_number(a: int, b: int) -> int:
    return a * b - a - b

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(frobenius_number(a, b))