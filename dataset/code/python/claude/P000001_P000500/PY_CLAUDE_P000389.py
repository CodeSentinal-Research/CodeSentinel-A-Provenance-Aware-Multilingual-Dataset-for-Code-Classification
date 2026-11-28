
n = int(input())
employees = [input().strip() for _ in range(n)]
dept = input().strip()
result = [e for e in employees if len(e.split()) > 1 and e.split()[1] == dept]
if result:
    for r in result: print(r)
else:
    print("No Records Found")
