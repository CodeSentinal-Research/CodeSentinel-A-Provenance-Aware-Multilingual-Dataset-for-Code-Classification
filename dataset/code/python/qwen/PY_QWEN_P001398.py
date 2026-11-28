import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    n = int(input_data[0])
    words = input_data[1:1+n]
    
    common_counts = None
    for word in words:
        word_counts = Counter(word)
        if common_counts is None:
            common_counts = word_counts
        else:
            for char in list(common_counts.keys()):
                common_counts[char] = min(common_counts[char], word_counts.get(char, 0))
                
    result = []
    for char, count in sorted(common_counts.items()):
        result.extend([char] * count)
        
    print("".join(result))

solve()

