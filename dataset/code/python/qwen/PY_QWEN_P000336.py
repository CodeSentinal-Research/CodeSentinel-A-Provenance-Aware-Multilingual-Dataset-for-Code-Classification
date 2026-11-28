a = input().strip()
b = input().strip()
def check(a, b):
    for i in range(len(a)):
        if a[:i] + b[i:] == (a[:i] + b[i:])[::-1]:
            return True
    return False
print("Yes" if check(a, b) or check(b, a) else "No")
