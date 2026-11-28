import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    heights = list(map(int, input_data[1:1+n]))
    
    left = 0
    right = n - 1
    max_area = 0
    
    while left < right:
        width = right - left
        height = min(heights[left], heights[right])
        max_area = max(max_area, width * height)
        
        if heights[left] < heights[right]:
            left += 1
        else:
            right -= 1
            
    print(max_area)

solve()

