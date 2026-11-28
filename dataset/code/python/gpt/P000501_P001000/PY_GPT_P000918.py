# problem title : Count Circular Arrangements
# Solve the stated task using standard input and standard output.
def circular_arrangements(n: int) -> int:
    if n <= 1:
        return 1
    ans = 1
    for i in range(1, n):
        ans *= i
    return ans

if __name__ == '__main__':
    n = int(input())
    print(circular_arrangements(n))
