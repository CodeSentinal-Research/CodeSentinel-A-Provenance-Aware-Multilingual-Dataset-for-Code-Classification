rows, cols = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(rows)]
peak = -1
for i in range(rows):
    for j in range(cols):
        val = matrix[i][j]
        is_peak = True
        for di, dj in [(-1,0), (1,0), (0,-1), (0,1)]:
            ni, nj = i + di, j + dj
            if 0 <= ni < rows and 0 <= nj < cols:
                if matrix[ni][nj] >= val:
                    is_peak = False
                    break
        if is_peak:
            peak = val
            break
    if peak != -1: break
print(peak)
