s = input().strip()
numRows = int(input())
if numRows == 1 or numRows >= len(s):
    print(s)
else:
    rows = [""] * numRows
    curr_row = 0
    step = 1
    for c in s:
        rows[curr_row] += c
        if curr_row == 0: step = 1
        elif curr_row == numRows - 1: step = -1
        curr_row += step
    print("".join(rows))
