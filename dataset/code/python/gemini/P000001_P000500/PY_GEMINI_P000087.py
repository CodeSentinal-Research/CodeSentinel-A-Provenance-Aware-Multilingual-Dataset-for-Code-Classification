def sum_of_natural_numbers(n: int) -> int:
    if n < 0:
        return 0
    return (n * (n + 1)) // 2

if __name__ == '__main__':
    n = int(input())
    print(sum_of_natural_numbers(n))