def move_negative(n, arr):
    arr[:] = [x for x in arr if x < 0] + [x for x in arr if x >= 0]
    return arr

n = int(input().strip())
arr = [int(x) for x in input().strip().split()]
print(move_negative(n, arr))