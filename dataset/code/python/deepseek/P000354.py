def count_occurrences(n, arr, x):
    return arr.count(x)

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    x = int(input())
    print(count_occurrences(n, arr, x))