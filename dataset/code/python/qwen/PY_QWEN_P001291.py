import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    hand = list(map(int, input_data[idx:idx+n]))
    
    counter = Counter(hand)
    hand.sort()
    
    for card in hand:
        if counter[card] == 0:
            continue
        for i in range(k):
            if counter[card + i] == 0:
                print("NO")
                return
            counter[card + i] -= 1
            
    print("YES")

if __name__ == "__main__":
    solve()

