def print_pascal_triangle(n: int) -> None:
    for i in range(n):
        row = []
        val = 1
        for j in range(i + 1):
            row.append(str(val))
            val = val * (i - j) // (j + 1)
        print(" ".join(row))

if __name__ == '__main__':
    n = int(input())
    print_pascal_triangle(n)