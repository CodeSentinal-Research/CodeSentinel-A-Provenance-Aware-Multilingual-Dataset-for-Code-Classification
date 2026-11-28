n = int(input())
courses = []
for _ in range(n):
    courses.append(input().split())
inst = input().strip()
for c in courses:
    if c[-1] == inst:
        print(" ".join(c))
