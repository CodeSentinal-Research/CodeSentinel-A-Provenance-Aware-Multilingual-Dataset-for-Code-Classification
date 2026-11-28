def find_element(N, arr, X):
    for i in range(N):
        if arr[i] == X:
            print("Found")
            break
    else:
        print("Not Found")

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    X = int(input())
    find_element(N, arr, X)

main()