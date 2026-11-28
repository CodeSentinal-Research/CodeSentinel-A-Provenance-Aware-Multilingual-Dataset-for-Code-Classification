# problem title : Print Floyd Triangle
# Floyd's triangle prints consecutive integers row by row.
rows = int(input())
value = 1
for width in range(1, rows + 1):
    line = []
    for _ in range(width):
        line.append(str(value)); value += 1
    print(' '.join(line))
