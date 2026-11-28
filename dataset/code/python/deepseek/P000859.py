def reverse_bits(n: int) -> int:
    return (((n & 0x0000FFFF) << 16) | ((n & 0xFF00FFFF) >> 16)) & 0xFFFFFFFF

if __name__ == "__main__":
    n = int(input("Enter a 32-bit unsigned integer: "))
    print("Reversed integer: ", reverse_bits(n))