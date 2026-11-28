def count_complete_subarrays(arr):
    count = 0
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            if len(set(arr[i:j+1])) == len(arr[i:j+1]):
                count += 1
    return count

N = int(input())
arr = list(map(int, input().split()))
print(count_complete_subarrays(arr))