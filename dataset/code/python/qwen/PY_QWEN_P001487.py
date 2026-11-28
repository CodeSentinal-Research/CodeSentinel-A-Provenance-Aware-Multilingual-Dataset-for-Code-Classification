import sys

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    n = int(input_data[0])
    queries = input_data[1:n+1]
    pattern = input_data[n+1]
    
    def matches(query, pat):
        qi = 0
        pi = 0
        while qi < len(query) and pi < len(pat):
            if query[qi] == pat[pi]:
                qi += 1
                pi += 1
            elif query[qi].isupper():
                return False
            else:
                qi += 1
        while qi < len(query):
            if query[qi].isupper():
                return False
            qi += 1
        return pi == len(pat)
        
    for q in queries:
        print("YES" if matches(q, pattern) else "NO")

solve()

