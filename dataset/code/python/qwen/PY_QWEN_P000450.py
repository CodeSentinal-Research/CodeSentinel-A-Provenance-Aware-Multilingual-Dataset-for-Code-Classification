n, k = map(int, input().split())
arr = list(map(int, input().split()))
curr = 1
miss = 0
idx = 0
while miss < k:
    if idx < n and arr[idx] == curr:
        idx += 1
    else:
        miss += 1
        if miss == k:
            print(curr)
            break
    curr += 1
