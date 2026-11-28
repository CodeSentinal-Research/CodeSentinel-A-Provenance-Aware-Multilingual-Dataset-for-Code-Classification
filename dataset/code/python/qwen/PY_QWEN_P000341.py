w1 = input().strip()
w2 = input().strip()
wt = input().strip()
def val(w):
    return int("".join(str(ord(c) - ord('a')) for c in w))
print("Yes" if val(w1) + val(w2) == val(wt) else "No")
