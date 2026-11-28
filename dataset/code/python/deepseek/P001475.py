def sort_colors(arr):
    start = 0
    end = len(arr) - 1

    i = 0
    while i <= end:
        if arr[i] == 0:
            arr[i], arr[start] = arr[start], arr[i]
            start += 1
            i += 1
        elif arr[i] == 2:
            arr[i], arr[end] = arr[end], arr[i]
            end -= 1
        else:
            i += 1

arr = list(map(int, input().split()))
sort_colors(arr)
print(' '.join(map(str, arr)))