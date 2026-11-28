import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    size = int(input_data[0])
    q = int(input_data[1])
    vals = list(map(int, input_data[2:2+q]))
    window = []
    for v in vals:
        window.append(v)
        if len(window) > size:
            window.pop(0)
        print(sum(window) / len(window))
solve()
