import sys

def solve():
    word = sys.stdin.readline().strip()
    n = len(word)
    results = []
    
    def backtrack(index, current, count):
        if index == n:
            if count > 0:
                results.append(current + str(count))
            else:
                results.append(current)
            return
        # Abbreviate current character
        backtrack(index + 1, current, count + 1)
        # Keep current character
        if count > 0:
            backtrack(index + 1, current + str(count) + word[index], 0)
        else:
            backtrack(index + 1, current + word[index], 0)
            
    backtrack(0, "", 0)
    for res in sorted(results):
        print(res)

if __name__ == "__main__":
    solve()

