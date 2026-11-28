import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    s = input_data[0]
    k = int(input_data[1])
    
    results = []
    
    def backtrack(start, current):
        if len(current) == k:
            results.append(current)
            return
        for i in range(start, len(s)):
            backtrack(i + 1, current + s[i])
            
    backtrack(0, "")
    for res in results:
        print(res)

if __name__ == "__main__":
    solve()

