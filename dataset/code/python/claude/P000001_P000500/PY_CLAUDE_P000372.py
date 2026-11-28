
n = int(input())
students = [input().strip() for _ in range(n)]
roll = input().strip()
found = None
for s in students:
    if s.split()[0] == roll:
        found = s
        break
print(found if found else "Record Not Found")
