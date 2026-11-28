# problem title : Check Power of Two
# Solve the stated task using standard input and standard output.
def is_power_of_two(n: int) -> bool:
    return n > 0 and (n & (n - 1)) == 0

if __name__ == '__main__':
    n = int(input())
    print("YES" if is_power_of_two(n) else "NO")
