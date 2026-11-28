def dec_to_hex_oct(n):
    if n == 0:
        return '0', '0'

    hex_digits = '0123456789ABCDEF'
    hex_val = ''
    while n:
        remainder = n % 16
        hex_val = hex_digits[remainder] + hex_val
        n //= 16

    oct_val = ''
    while n:
        oct_val = str(n % 8) + oct_val
        n //= 8

    return hex_val, oct_val


def main():
    n = int(input("Enter a decimal number: "))
    hex_val, oct_val = dec_to_hex_oct(n)
    print("Hexadecimal representation: ", hex_val)
    print("Octal representation: ", oct_val)


if __name__ == "__main__":
    main()