def count_zeros(matrix):
    count = 0
    for row in matrix:
        count += row.count(0)
    return count

def main():
    N = int(input().strip())
    matrix = []
    for _ in range(N):
        row = list(map(int, input().strip().split()))
        matrix.append(row)
    print(count_zeros(matrix))

main()