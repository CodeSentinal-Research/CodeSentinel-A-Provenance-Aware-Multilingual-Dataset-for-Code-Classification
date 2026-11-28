def find_last_occurrence(n, arr, x):
    for i in range(n-1, -1, -1):
        if arr[i] == x:
            return i
    return -1

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    x = int(input())
    print(find_last_occurrence(n, arr, x))

if __name__ == "__main__":
    main()