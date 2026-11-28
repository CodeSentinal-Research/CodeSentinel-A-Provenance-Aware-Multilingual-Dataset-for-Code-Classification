def find_element(N, arr, X):
    for i in range(N):
        if arr[i] > X:
            return i
    return -1

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    X = int(input())
    print(find_element(N, arr, X))

if __name__ == "__main__":
    main()