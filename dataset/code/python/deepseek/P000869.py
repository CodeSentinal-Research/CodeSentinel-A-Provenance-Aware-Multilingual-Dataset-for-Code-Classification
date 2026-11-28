def divide(dividend: int, divisor: int) -> int:
    if divisor == 0:
        return float('inf') if dividend == 0 else 0
    if dividend == int(dividend) and divisor == int(divisor):
        return dividend // divisor

    if dividend == divisor:
        return 1
    if dividend == 0:
        return 0

    sign = -1 if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0) else 1
    dividend = abs(dividend)
    divisor = abs(divisor)
    quotient = 0

    for i in range(31, -1, -1):
        if (dividend >> i) - divisor >= 0:
            quotient += 1 << i
            dividend -= divisor << i

    return sign * quotient

def main():
    dividend = int(input("Enter dividend: "))
    divisor = int(input("Enter divisor: "))
    print(divide(dividend, divisor))

if __name__ == "__main__":
    main()