import sys

def solve():
    s = sys.stdin.readline().strip()
    k = int(sys.stdin.readline())
    vowels = set('aeiouAEIOU')
    
    count = 0
    for i in range(k):
        if s[i] in vowels:
            count += 1
            
    max_vowels = count
    
    for i in range(k, len(s)):
        if s[i] in vowels:
            count += 1
        if s[i-k] in vowels:
            count -= 1
        max_vowels = max(max_vowels, count)
        
    print(max_vowels)

solve()

