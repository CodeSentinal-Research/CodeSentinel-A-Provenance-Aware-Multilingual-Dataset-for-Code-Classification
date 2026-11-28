n = int(input())
arr = list(map(int, input().split()))
x = int(input())
print("Missing" if x not in arr else "Present")
