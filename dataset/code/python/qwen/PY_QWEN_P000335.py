q = int(input())
queries = [input().strip() for _ in range(q)]
pattern = input().strip()
def match(word, pat):
    i = 0
    for ch in word:
        if i < len(pat) and ch == pat[i]:
            i += 1
        elif ch.isupper():
            return False
    return i == len(pat)
res = []
for w in queries:
    res.append("true" if match(w, pattern) else "false")
print(" ".join(res))
