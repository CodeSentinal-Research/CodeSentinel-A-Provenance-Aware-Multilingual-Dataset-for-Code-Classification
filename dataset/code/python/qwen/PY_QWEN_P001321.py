import sys

def solve():
    digits = sys.stdin.readline().strip()
    mapping = {
        '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
        '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
    }
    
    if not digits:
        return
        
    results = []
    
    def backtrack(index, current):
        if index == len(digits):
            results.append(current)
            return
        for char in mapping.get(digits[index], ''):
            backtrack(index + 1, current + char)
            
    backtrack(0, "")
    for res in results:
        print(res)

if __name__ == "__main__":
    solve()

