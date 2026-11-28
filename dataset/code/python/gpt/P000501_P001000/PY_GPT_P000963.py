# problem title : Chicken McNugget Numbers
# Solve the stated task using standard input and standard output.
def count_non_purchasable(a: int, b: int) -> int:
    return (a - 1) * (b - 1) // 2

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(count_non_purchasable(a, b))
