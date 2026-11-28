import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    seats = list(map(int, input_data[1:1+n]))
    
    max_dist = 0
    last_occupied = -1
    
    for i in range(n):
        if seats[i] == 1:
            if last_occupied == -1:
                max_dist = i
            else:
                max_dist = max(max_dist, (i - last_occupied) // 2)
            last_occupied = i
            
    if last_occupied != -1:
        max_dist = max(max_dist, n - 1 - last_occupied)
        
    print(max_dist)

solve()

