# problem title : Largest and Smallest Digit
# Solve the stated task using standard input and standard output.
def min_max_digit(n: int):
    digits = [int(d) for d in str(abs(n))]
    return min(digits), max(digits)

if __name__ == '__main__':
    n = int(input())
    mn, mx = min_max_digit(n)
    print(f"{mn} {mx}")
