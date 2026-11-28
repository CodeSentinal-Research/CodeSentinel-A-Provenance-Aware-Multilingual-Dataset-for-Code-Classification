# problem title : Binary to Decimal Conversion
# Solve the stated task using standard input and standard output.
def binary_to_decimal(s: str) -> int:
    return int(s.strip(), 2)

if __name__ == '__main__':
    s = input().strip()
    print(binary_to_decimal(s))
