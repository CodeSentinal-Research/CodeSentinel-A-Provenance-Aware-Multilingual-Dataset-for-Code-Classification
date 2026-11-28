import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    words = []
    for _ in range(n):
        words.append(input_data[idx]); idx += 1
    pattern = input_data[idx]; idx += 1
    
    def matches(word, pat):
        if len(word) != len(pat):
            return False
        w_to_p = {}
        p_to_w = {}
        for w, p in zip(word, pat):
            if w in w_to_p:
                if w_to_p[w] != p:
                    return False
            else:
                w_to_p[w] = p
            if p in p_to_w:
                if p_to_w[p] != w:
                    return False
            else:
                p_to_w[p] = w
        return True
        
    results = []
    for word in words:
        if matches(word, pattern):
            results.append(word)
            
    for word in results:
        print(word)

solve()

