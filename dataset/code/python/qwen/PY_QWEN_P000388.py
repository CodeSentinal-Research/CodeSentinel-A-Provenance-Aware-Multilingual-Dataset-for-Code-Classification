n = int(input())
passports = {}
for _ in range(n):
    parts = input().split()
    passports[parts[0]] = " ".join(parts[1:])
pid = input().strip()
print(passports.get(pid, "Passport Not Found"))
