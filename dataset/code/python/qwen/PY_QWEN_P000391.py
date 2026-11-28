n = int(input())
studs = []
for _ in range(n):
    studs.append(input().split())
min_gpa = float(input())
for s in studs:
    if float(s[-1]) >= min_gpa:
        print(" ".join(s))
