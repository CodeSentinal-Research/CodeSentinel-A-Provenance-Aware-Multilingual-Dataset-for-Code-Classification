
n=int(input());words=[input() for _ in range(n)]
if not words: print('');exit()
pref=words[0]
for w in words[1:]:
    while not w.startswith(pref): pref=pref[:-1]
    if not pref: break
print(pref)
