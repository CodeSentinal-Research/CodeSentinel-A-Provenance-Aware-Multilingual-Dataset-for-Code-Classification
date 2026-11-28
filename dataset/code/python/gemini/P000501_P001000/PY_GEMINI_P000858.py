def find_position(n: int) -> int:
    if n <= 0 or (n & (n - 1)) != 0:
        return -1
    return (n & -n).bit_length()

if __name__ == '__main__':
    n = int(input())
    print(find_position(n))