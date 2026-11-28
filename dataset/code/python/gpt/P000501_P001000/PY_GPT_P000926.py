# problem title : Decimal to Octal and Hexadecimal
# Solve the stated task using standard input and standard output.
def convert_bases(n: int):
    return oct(n)[2:], hex(n)[2:].upper()

if __name__ == '__main__':
    n = int(input())
    o, h = convert_bases(n)
    print(f"{o} {h}")
