import sys

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    first_line = input_data[0].split()
    n = int(first_line[0])
    m = int(first_line[1])
    threshold = int(first_line[2])
    
    matrix = []
    for i in range(1, n + 1):
        matrix.append(list(map(int, input_data[i].split())))
        
    prefix = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
            
    def get_sum(r1, c1, r2, c2):
        return prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1]
        
    max_side = 0
    low, high = 1, min(n, m)
    
    while low <= high:
        mid = (low + high) // 2
        found = False
        for i in range(mid, n + 1):
            for j in range(mid, m + 1):
                if get_sum(i - mid + 1, j - mid + 1, i, j) <= threshold:
                    found = True
                    break
            if found:
                break
        if found:
            max_side = mid
            low = mid + 1
        else:
            high = mid - 1
            
    print(max_side)

solve()

