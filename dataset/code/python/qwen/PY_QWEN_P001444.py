import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    words = []
    for _ in range(n):
        words.append(input_data[idx]); idx += 1
        
    counter = Counter(words)
    length = 0
    
    # Palindromes like "aa" + "bb" + ...
    # Or "ab" + "ba"
    
    used = set()
    for word in counter:
        if word[0] == word[1]:
            # Self-palindrome
            count = counter[word]
            length += (count // 2) * 4
            if count % 2 == 1:
                length += 2 # Can put one in middle
        else:
            rev = word[::-1]
            if rev in counter and word not in used:
                pairs = min(counter[word], counter[rev])
                length += pairs * 4
                used.add(word)
                used.add(rev)
                
    print(length)

solve()

