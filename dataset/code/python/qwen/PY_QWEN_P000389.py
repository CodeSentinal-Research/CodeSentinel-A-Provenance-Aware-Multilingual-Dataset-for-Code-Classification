n = int(input())
emps = []
for _ in range(n):
    emps.append(input().split())
dept = input().strip()
found = False
for e in emps:
    if e[-1] == dept:
        print(" ".join(e))
        found = True
if not found:
    print("No Records Found")
