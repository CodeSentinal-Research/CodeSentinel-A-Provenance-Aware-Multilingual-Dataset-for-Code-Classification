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
        grid.append(list(map(int, input_data[idx:idx+c])))
        idx += c
        
    heights = [0] * c
    max_area = 0
    
    for i in range(r):
        for j in range(c):
            if grid[i][j] == 1:
                heights[j] += 1
            else:
                heights[j] = 0
                
        # Largest Rectangle in Histogram
        stack = []
        for j in range(c + 1):
            h = heights[j] if j < c else 0
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]
                width = j if not stack else j - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(j)
            
    print(max_area)

if __name__ == "__main__":
    solve()

