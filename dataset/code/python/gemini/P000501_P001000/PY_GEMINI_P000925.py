def binary_to_decimal(s: str) -> int:
    return int(s.strip(), 2)

if __name__ == '__main__':
    s = input().strip()
    print(binary_to_decimal(s))