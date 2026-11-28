import random


# Python program to solve Gold Mine problem
def collectGold(gold, x, y, n, m, sol_arr):
    # Base condition.
    if (x < 0) or (x == n) or (y == m):
        return 0

    # Right upper diagonal
    rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m, sol_arr)

    # right
    right = collectGold(gold, x, y + 1, n, m, sol_arr)

    # Lower right diagonal
    rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m, sol_arr)

    # Return the maximum and store the value
    sol_arr[x][y] = gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right)
    return gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right)


def getMaxGold(gold, n, m, sol_arr):
    maxGold = 0

    for i in range(n):
        # Recursive function call for  ith row.
        goldCollected = collectGold(gold, i, 0, n, m, sol_arr)
        maxGold = max(maxGold, goldCollected)

    return maxGold


# Driver Code
# gold = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]]

m, n = 20, 20
gold = [
    [random.randrange(0, 2) * random.randrange(1, 10) for _ in range(m)]
    for _ in range(n)
]
sol_arr = [[0 for j in range(m)] for i in range(n)]
print(getMaxGold(gold, n, m, sol_arr))
# get the largest item
max_item = max([max(arr) for arr in sol_arr])
# find the length of the largest item + 1
max_item_len = len(str(max_item)) + 1

print("Gold Array")
for row in gold:
    for item in row:
        length = len(str(item))
        print(" " * (max_item_len - length) + str(item), end="")
    print()

print("Solution Array")
for row in sol_arr:
    for item in row:
        length = len(str(item))
        print(" " * (max_item_len - length) + str(item), end="")
    print()

# find max item index
max_starting_index = 0
for row in range(n):
    if sol_arr[row][0] > sol_arr[max_starting_index][0]:
        max_starting_index = row

print("Path Array")
# the index is the column and the nth item is the row
path = [max_starting_index]
max_item = max_starting_index
for col in range(1, m):
    top_item = -1
    if path[-1] != 0:
        top_item = sol_arr[path[-1] - 1][col]
    middle_item = sol_arr[path[-1]][col]
    bottom_item = -1
    if path[-1] != n - 1:
        bottom_item = sol_arr[path[-1] + 1][col]
    next_row = 0
    if top_item >= middle_item and top_item >= bottom_item:
        next_row = path[-1] - 1
    elif middle_item >= top_item and middle_item >= bottom_item:
        next_row = path[-1]
    elif bottom_item >= top_item and bottom_item >= middle_item:
        next_row = path[-1] + 1
    path.append(next_row)
print(path)

print("2D Path")
# make 2d walking array
twoD_path = [["" for j in range(m)] for i in range(n)]
for j in range(m):
    for i in range(n):
        twoD_path[i][j] = "X" if path[j] == i else "."

for row in twoD_path:
    for item in row:
        print(item + " ", end="")
    print()