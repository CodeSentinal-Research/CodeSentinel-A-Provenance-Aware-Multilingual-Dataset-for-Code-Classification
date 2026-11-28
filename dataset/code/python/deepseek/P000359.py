def search_positive_number(N, arr):
    for i in range(N):
        if arr[i] > 0:
            return i
    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(search_positive_number(N, arr))

if __name__ == "__main__":
    main()