n = input().strip()
print(sum(1 for x in n if int(x) % 2 == 0))
