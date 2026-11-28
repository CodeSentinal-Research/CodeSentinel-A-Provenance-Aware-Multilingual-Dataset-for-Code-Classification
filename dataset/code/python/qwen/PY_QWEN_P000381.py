n = int(input())
contacts = {}
for _ in range(n):
    parts = input().split()
    contacts[parts[0]] = " ".join(parts[1:])
name = input().strip()
print(contacts.get(name, "Contact Not Found"))
