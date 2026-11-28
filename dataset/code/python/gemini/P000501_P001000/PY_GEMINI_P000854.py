def count_set_bits(n: int) -> int:
    count = 0
    while n > 0:
        n &= (n - 1)
        count += 1
    return count

if __name__ == '__main__':
    n = int(input())
    print(count_set_bits(n))