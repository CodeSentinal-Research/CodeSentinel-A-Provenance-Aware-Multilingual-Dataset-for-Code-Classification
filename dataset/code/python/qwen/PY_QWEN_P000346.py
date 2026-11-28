s = input().strip()
n = int(input())
words = [input().strip() for _ in range(n)]
def is_sub(w):
    it = iter(s)
    return all(c in it for c in w)
valid = [w for w in words if is_sub(w)]
if not valid:
    print("")
else:
    print(sorted(valid, key=lambda x: (-len(x), x))[0])
