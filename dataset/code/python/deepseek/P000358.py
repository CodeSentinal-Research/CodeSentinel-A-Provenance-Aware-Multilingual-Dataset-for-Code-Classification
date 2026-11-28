def search_negative(N, arr):
    for i in range(N):
        if arr[i] < 0:
            return i
    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    result = search_negative(N, arr)
    print(result)

if __name__ == "__main__":
    main()