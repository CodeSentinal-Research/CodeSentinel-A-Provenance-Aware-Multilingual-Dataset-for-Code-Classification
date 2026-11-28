s = input().strip()
t = input().strip()
if abs(len(s) - len(t)) > 1:
    print("No")
else:
    if len(s) > len(t): s, t = t, s
    for i in range(len(s)):
        if s[i] != t[i]:
            if len(s) == len(t):
                print("Yes" if s[i+1:] == t[i+1:] else "No")
            else:
                print("Yes" if s[i:] == t[i+1:] else "No")
            break
    else:
        print("Yes" if len(s) != len(t) else "No")
