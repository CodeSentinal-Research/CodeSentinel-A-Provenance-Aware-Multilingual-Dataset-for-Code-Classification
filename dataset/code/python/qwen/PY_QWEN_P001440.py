import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    s = input_data[idx]; idx += 1
    n = int(input_data[idx]); idx += 1
    
    dictionary = []
    for _ in range(n):
        dictionary.append(input_data[idx]); idx += 1
        
    best = ""
    for word in dictionary:
        it = iter(s)
        if all(c in it for c in word):
            if len(word) > len(best) or (len(word) == len(best) and word < best):
                best = word
                
    print(best)

solve()

