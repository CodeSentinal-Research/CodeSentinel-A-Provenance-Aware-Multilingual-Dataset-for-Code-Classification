def count_strictly_increasing_windows():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))

    count = 0
    for i in range(N - K + 1):
        if all(arr[i] < arr[i+1] for i in range(i, i+K)):
            count += 1

    print(count)

def main():
    count_strictly_increasing_windows()

if __name__ == "__main__":
    main()