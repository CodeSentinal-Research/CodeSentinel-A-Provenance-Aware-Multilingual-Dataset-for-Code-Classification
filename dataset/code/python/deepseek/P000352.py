def find_first_occurrence(N, arr, X):
    for i in range(N):
        if arr[i] == X:
            return i
    return -1

N = int(input())
arr = list(map(int, input().split()))
X = int(input())
print(find_first_occurrence(N, arr, X))