def count_positive_numbers():
    N = int(input().strip())
    numbers = [int(i) for i in input().strip().split()]
    Q = int(input().strip())

    for _ in range(Q):
        L, R = map(int, input().strip().split())
        count = sum(1 for num in numbers[L-1:R] if num > 0)
        print(count)

if __name__ == "__main__":
    count_positive_numbers()