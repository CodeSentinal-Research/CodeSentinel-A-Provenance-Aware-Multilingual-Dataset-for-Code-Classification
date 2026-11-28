import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n = int(input_data[0])
    tickets = list(map(int, input_data[1:n+1]))
    k = int(input_data[n+1])
    time = 0
    while tickets[k] > 0:
        for i in range(n):
            if tickets[i] > 0:
                tickets[i] -= 1
                time += 1
                if i == k and tickets[k] == 0:
                    print(time)
                    return
solve()
