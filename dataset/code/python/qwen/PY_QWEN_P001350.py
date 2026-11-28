import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    
    count = 0
    result = ""
    
    def backtrack(current):
        nonlocal count, result
        if len(current) == n:
            count += 1
            if count == k:
                result = current
            return
        for char in 'abc':
            if not current or current[-1] != char:
                backtrack(current + char)
                if result:
                    return
                    
    backtrack("")
    print(result)

if __name__ == "__main__":
    solve()

