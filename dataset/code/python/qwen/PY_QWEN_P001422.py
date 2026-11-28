import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    rows = [
        set("qwertyuiop"),
        set("asdfghjkl"),
        set("zxcvbnm")
    ]
    
    results = []
    for _ in range(n):
        word = input_data[idx]; idx += 1
        lower_word = word.lower()
        for row in rows:
            if all(c in row for c in lower_word):
                results.append(word)
                break
                
    for word in results:
        print(word)

solve()

