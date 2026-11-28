def sum_of_array_elements(n, arr):
    return sum(arr)

n = int(input().strip())
arr = list(map(int, input().strip().split()))
print(sum_of_array_elements(n, arr))