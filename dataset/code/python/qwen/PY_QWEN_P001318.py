import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    r = int(input_data[idx]); idx += 1
    c = int(input_data[idx]); idx += 1
    
    grid = []
    for _ in range(r):
        grid.append(input_data[idx]); idx += 1
        
    word = input_data[idx]; idx += 1
    
    def backtrack(i, j, k):
        if k == len(word):
            return True
        if i < 0 or i >= r or j < 0 or j >= c or grid[i][j] != word[k]:
            return False
            
        temp = grid[i]
        grid[i] = temp[:j] + '#' + temp[j+1:]
        
        found = (backtrack(i+1, j, k+1) or
                 backtrack(i-1, j, k+1) or
                 backtrack(i, j+1, k+1) or
                 backtrack(i, j-1, k+1))
                 
        grid[i] = temp
        return found
        
    for i in range(r):
        for j in range(c):
            if backtrack(i, j, 0):
                print("YES")
                return
                
    print("NO")

if __name__ == "__main__":
    solve()

