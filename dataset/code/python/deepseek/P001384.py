def find_duplicates(N, arr):
    duplicates = []
    for i in range(N):
        if arr[abs(arr[i])-1] < 0:
            duplicates.append(abs(arr[i]))
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1]
        else:
            arr[abs(arr[i])-1] *= -1
    duplicates = list(set(duplicates))
    duplicates.sort()
    for num in duplicates:
        print(num)

if __name__ == "__main__":
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    find_duplicates(N, arr)