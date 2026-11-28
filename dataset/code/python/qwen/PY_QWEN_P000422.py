n = int(input())
studs = [input().split() for _ in range(n)]
min_cgpa = float(input())
max_income = float(input())
for s in studs:
    if float(s[-2]) >= min_cgpa and float(s[-1]) <= max_income:
        print(" ".join(s))
