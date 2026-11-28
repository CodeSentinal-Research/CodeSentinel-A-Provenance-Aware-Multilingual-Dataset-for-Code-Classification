def print_floyd_triangle(rows: int) -> None:
    num = 1
    for i in range(1, rows + 1):
        line = []
        for _ in range(i):
            line.append(str(num))
            num += 1
        print(" ".join(line))

if __name__ == '__main__':
    rows = int(input())
    print_floyd_triangle(rows)