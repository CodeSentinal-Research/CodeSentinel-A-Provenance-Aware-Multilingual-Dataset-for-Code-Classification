import sys

def solve():
    s = sys.stdin.readline().strip()
    vowels = set('aeiou')
    n = len(s)
    
    count = 0
    for i in range(n):
        if s[i] not in vowels:
            continue
        has_a = has_e = has_i = has_o = has_u = False
        for j in range(i, n):
            if s[j] not in vowels:
                break
            if s[j] == 'a': has_a = True
            elif s[j] == 'e': has_e = True
            elif s[j] == 'i': has_i = True
            elif s[j] == 'o': has_o = True
            elif s[j] == 'u': has_u = True
            
            if has_a and has_e and has_i and has_o and has_u:
                count += 1
                
    print(count)

solve()

