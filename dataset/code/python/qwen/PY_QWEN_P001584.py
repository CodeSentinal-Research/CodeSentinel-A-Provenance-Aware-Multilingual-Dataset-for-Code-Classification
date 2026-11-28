import sys

def solve():
    s = sys.stdin.readline().strip()
    k = int(sys.stdin.readline())
    vowels = set('aeiouAEIOU')
    
    left = 0
    vowel_count = 0
    max_len = 0
    
    for right in range(len(s)):
        if s[right] in vowels:
            vowel_count += 1
        while vowel_count > k:
            if s[left] in vowels:
                vowel_count -= 1
            left += 1
        max_len = max(max_len, right - left + 1)
        
    print(max_len)

solve()

