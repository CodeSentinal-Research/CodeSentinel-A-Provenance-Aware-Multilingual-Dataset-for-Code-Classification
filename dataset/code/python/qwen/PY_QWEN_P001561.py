import sys
from collections import Counter

def solve():
    s = sys.stdin.readline().strip()
    m = int(sys.stdin.readline())
    words = sys.stdin.readline().split()
    
    if not words:
        print(-1)
        return
        
    word_len = len(words[0])
    total_words = len(words)
    word_count = Counter(words)
    n = len(s)
    
    results = []
    
    for i in range(word_len):
        left = i
        right = i
        current_count = Counter()
        matched = 0
        
        while right + word_len <= n:
            word = s[right:right+word_len]
            right += word_len
            
            if word in word_count:
                current_count[word] += 1
                if current_count[word] == word_count[word]:
                    matched += 1
                    
                while current_count[word] > word_count[word]:
                    left_word = s[left:left+word_len]
                    current_count[left_word] -= 1
                    if current_count[left_word] < word_count[left_word]:
                        matched -= 1
                    left += word_len
                    
                if matched == len(word_count):
                    results.append(left)
            else:
                current_count.clear()
                matched = 0
                left = right
                
    if results:
        print(*sorted(results))
    else:
        print(-1)

solve()

