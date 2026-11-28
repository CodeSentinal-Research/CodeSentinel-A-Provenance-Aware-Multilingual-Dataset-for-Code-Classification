n = int(input())
arr = list(map(int, input().split()))
slow = arr[0]
fast = arr[arr[0]]
while slow != fast:
    slow = arr[slow]
    fast = arr[arr[fast]]
slow = 0
while slow != fast:
    slow = arr[slow]
    fast = arr[fast]
print(slow)
