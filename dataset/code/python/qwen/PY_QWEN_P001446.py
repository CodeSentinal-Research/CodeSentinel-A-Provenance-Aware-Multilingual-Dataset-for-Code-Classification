import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    sentence1 = input_data[idx].split(); idx += 1
    sentence2 = input_data[idx].split(); idx += 1
    p = int(input_data[idx]); idx += 1
    
    similar_pairs = set()
    for _ in range(p):
        w1 = input_data[idx]; idx += 1
        w2 = input_data[idx]; idx += 1
        similar_pairs.add((w1, w2))
        similar_pairs.add((w2, w1))
        
    if len(sentence1) != len(sentence2):
        print("NO")
        return
        
    for w1, w2 in zip(sentence1, sentence2):
        if w1 != w2 and (w1, w2) not in similar_pairs:
            print("NO")
            return
            
    print("YES")

solve()

