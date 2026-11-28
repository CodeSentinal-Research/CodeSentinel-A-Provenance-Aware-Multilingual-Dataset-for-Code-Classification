import sys
from collections import defaultdict
import bisect

def num_matching_subseq(s: str, words) -> int:
    pos = defaultdict(list)
    for i, c in enumerate(s):
        pos[c].append(i)
    
    count = 0
    for w in words:
        curr = -1
        possible = True
        for c in w:
            idx_list = pos[c]
            i = bisect.bisect_right(idx_list, curr)
            if i == len(idx_list):
                possible = False
                break
            curr = idx_list[i]
        if possible:
            count += 1
    return count

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        words = tokens[1:]
        print(num_matching_subseq(s, words))

if __name__ == '__main__':
    main()