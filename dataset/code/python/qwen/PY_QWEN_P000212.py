size, n = map(int, input().split())
bed = list(map(int, input().split()))
count = 0
for i in range(size):
    if bed[i] == 0:
        empty_left = (i == 0) or (bed[i - 1] == 0)
        empty_right = (i == size - 1) or (bed[i + 1] == 0)
        if empty_left and empty_right:
            bed[i] = 1
            count += 1
if count >= n:
    print("Yes")
else:
    print("No")
